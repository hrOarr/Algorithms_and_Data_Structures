void _seive()
{
    vis[1] = 1;
    for(int i=4; i<N; i+=2)vis[i]=1;
    for(int i=3; i*i<=N; i+=2)
    {
        if( vis[i] )continue;
        for(int j=i*i; j<N; j+=(i+i))
            vis[j]=1;
    }
    prim[++id] = 2;
    for(int i=3; i<N; i+=2)
    {
        if(vis[i])continue;
        prim[++id] = i;
    }
}
