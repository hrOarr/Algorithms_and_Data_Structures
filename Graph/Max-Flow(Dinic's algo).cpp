struct Edge
{
    ll to,rev;
    ll flw,cap;
};
vector<Edge>Vec[N];
void AddEdge( int u,int v,ll cap )
{
    Edge x = { v,Vec[v].size(),0,cap };
    Edge y = { u,Vec[u].size(),0,cap };
    Vec[u].pb(x);
    Vec[v].pb(y);
}

bool Bfs(int St,int Ed)
{
    fill( Lev,Lev+N,-1 );
    Lev[St] = 0;
    int nw = 0;
    Q[nw++] = St;
    for(int i=0;i<nw;i++)
    {
        int u = Q[i];
        for(int j=0;j<Vec[u].size();j++)
        {
            Edge &e = Vec[u][j];
            int v = e.to;
            int flw = e.flw;
            int cap = e.cap;
            if( Lev[v]==-1&&flw<cap )
            {
                Lev[v] = Lev[u]+1;
                Q[nw++] = v;
            }
        }
    }
    return (Lev[Ed]!=-1);
}

ll dinic_dfs( int u,int Ed,int flow )
{
    if( u==Ed ) return flow;
    for(;Work[u]<(int)Vec[u].size();Work[u]++)
    {
        Edge &e = Vec[u][ Work[u] ];
        int v = e.to;
        int flw = e.flw;
        int cap = e.cap;
        if( cap<=flw ) continue;
        if( Lev[v]==Lev[u]+1 )
        {
            ll tmp_flow = dinic_dfs( v,Ed,min(flow,cap-flw) );
            if( tmp_flow>0 )
            {
                e.flw += tmp_flow;
                Vec[v][e.rev].flw -= tmp_flow;
                return tmp_flow;
            }
        }
    }
    return 0;
}

ll max_flow( int St,int Ed )
{
    ll Res = 0;
    while(Bfs( St,Ed ))
    {
        fill(Work,Work+N,0);
        while( ll Ret = dinic_dfs(St,Ed,INT_MAX) )
        {
            Res += Ret;
            if( !Ret )break;
        }
    }
    return Res;
}