vector<int>rs;
void dfs(int u,int p)
{
    vis[u]=1;
    for(auto v:vec[u])
    {
        if(v==p||vis[v])continue;
        dfs(v,u);
    }
    rs.push_back(u);
}
void _print()
{
    cout<<"DFS traversal:";
    for(auto x:rs)cout<<" "<<x;
    cout<<"\n";
}
