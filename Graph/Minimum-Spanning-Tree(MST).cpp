int _find(int x)
{
    if(pr[x]==x)return x;
    return pr[x]=_find(pr[x]);
}
void _union(int u,int v)
{
    int p=_find(u);
    int q=_find(v);
    pr[p]=q;
}
void _mst()
{
    int cost=0;
    for(auto x:vec)
    {
        int w=x.fs,u=x.sc.fs,v=x.sc.sc;
        int p=_find(u);
        int q=_find(v);
        if(p==q)continue;
        pr[p]=q;
        cost+=w;
        newvec[u].pb(v);
        newvec[v].pb(u);
    }
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)pr[i]=i;
    while(m--)
    {
        int u,v,w;cin>>u>>v>>w;
        vec.pb(make_pair(w,make_pair(u,v)));
    }
    sort(vec.begin(),vec.end());
    _mst();
}
