void dfs(int u)
{
    vis[u]=true;
    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];
        if(!vis[v] )dfs(v);
    }
    top.push_back(u);
}
void dfs2( int u )
{
    vis[u] = true;
    scc[u] = cmp;
    for(int i=0; i<rev[u].size(); i++)
    {
        int v = rev[u][i];
        if( !vis[v] )dfs2(v);
    }
}
void dfs3( int u )
{
    vis[u] = true;
    if( Adj[u].size()>1 )
    {
        Flag = false;
        return ;
    }
    for(int i=0; i<Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if( !vis[v] )dfs3(v);
    }
}
int main()
{
    for(int i=0; i<=nod; i++)
    {
        if( !vis[i] )dfs(i);
    }
    memset( vis,0,sizeof vis );
    reverse( top.begin(),top.end() );
    for(int i=0; i<top.size(); i++)
    {
        if( !vis[ top[i] ] )
            ++cmp,dfs2(top[i]);
    }
    for(int i=0; i<=nod; i++)
    {
        for(int j=0; j<vec[i].size(); j++)
        {
            int v = vec[i][j];
            if( scc[i]!=scc[v] )
                Adj[scc[i]].push_back(scc[v]);
        }
    }
    Flag = true;
    memset( vis,0,sizeof vis );
    dfs3( scc[0] );
}
