bool dfs(int u)
{
    for(auto v:vec[u])
    {
        if(vis[v])continue;
        vis[v]=1;
        if(!Pair[v]||dfs(Pair[v]))
        {
            Pair[v]=u;
            return true;
        }
    }
    return false;
}
void bpm()
{
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        if(dfs(i))rs++;
    }
}