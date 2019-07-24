void dfs1(int u,int p)
{
    sz[u]=1;
    ++nod;
    for(auto v:st[u])
    {
        if(v==p)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
    }
}
int dfs2(int u,int p)
{
    for(auto v:st[u])
    {
        if(v==p||sz[v]<=nod/2)continue;
        return dfs2(v,u);
    }
    return u;
}
void decomposed(int rt,int p)
{
    nod=0;
    dfs1(rt,rt);
    int cntr=dfs2(rt,rt);
    if(p==-1)p=cntr;
    pr[cntr]=p;
    for(auto it=st[cntr].begin();it!=st[cntr].end();++it)
    {
        int v=*it;
        st[v].erase(cntr);
        decomposed(v,cntr);
    }
    st[cntr].clear();
}
