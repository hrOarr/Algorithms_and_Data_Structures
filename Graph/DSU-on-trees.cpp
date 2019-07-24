void Add( int u,int par )
{
    int now = Col[u];
    Cnt[now]++;
    if( MX<Cnt[now] )
        MX = Cnt[now],Sum = now;
    else if( MX==Cnt[now] )
        Sum += now;
    for(auto v:vec[u])
    {
        if(v!=par&&!vis[v])
            Add( v,u );
    }
}

void Remove( int u,int par )
{
    Cnt[Col[u]]--;
    for(auto v:vec[u])
    {
        if(v!=par&&!vis[v])
            Remove(v,u);
    }
}

void dfs( int u,int par,bool F )
{
    int mx = -1,id = -1;
    for(auto v:vec[u])
    {
        if( v!=par && Child[v]>mx )
            mx = Child[v],id = v;
    }
    for(auto v:vec[u])
    {
        if( v!=par && v!=id )
            dfs( v,u,1 );
    }
    if( id!=-1 )
        dfs( id,u,0 ),vis[id] = 1;
    Add( u,par );
    if( id!=-1 ) vis[id] = 0;
    Res[u] = Sum;
    if( F )
        Remove(u,par),MX=Sum=0;
}

void DFS( int u,int par )
{
    Child[u] = 1;
    for(auto v:vec[u])
    {
        if(v==par)continue;
        DFS(v,u);
        Child[u] += Child[v];
    }
}