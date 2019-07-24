void _init()
{
    tm=0;
    for(int i=0;i<N;i++)
    {
        vs[i]=ap[i]=0;
        pr[i]=-1;
        low[i]=disc[i]=0;
    }
}
void dfs(int u)
{
    vs[u]=1;
    low[u]=disc[u]=++tm;
    int sz=0;
    for(auto v:vec[u])
    {
        if(!vs[i])
        {
            sz++,pr[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(pr[u]!=-1&&low[v]>=disc[u])ap[u]=1; // articulation point
            else if(pr[u]==-1&&sz>1)ap[u]=1; // articulation point
        }
        else if(v!=pr[u])low[u]=min(low[u],disc[v]);
    }
}
