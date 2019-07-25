void bfs(int s)
{
    queue<int>q1;
    q1.push(s);
    vis[s]=1;
    vector<int>rs;
    while(!q1.empty())
    {
        int u=q1.front();
        q1.pop();
        rs.push_back(u);
        for(auto v:vec[u])
        {
            if(vis[v])continue;
            vis[v]=1;
            q1.push(v);
        }
    }
    cout<<"bfs traversal order:";
    for(auto x:rs)cout<<" "<<x;
    cout<<"\n";
}
