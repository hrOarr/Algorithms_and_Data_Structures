int _find(int x)
{
    if(pr[x]==x)return x;
    return pr[x]=_find(pr[x]);
}
void _union(int u,int v)
{
    int p=_find(u);
    int q=_find(v);
    if(p==q)return;
    if(rnk[p]>rnk[q])pr[q]=p;
    else if(rnk[p]<rnk[q])pr[p]=q;
    else pr[p]=q,rnk[q]++;
}

// Optimized path compression

void _union(int u,int v)
{
    if(sz[u]<sz[v])
    {
        pr[u]=pr[v];
        sz[v]+=sz[u];
    }
    else
    {
        pr[v]=pr[u];
        sz[u]+=sz[u];
    }
}
int isCycle(vector<int>adj[],int n)
{
    for(int i=0;i<n;i++) {
        for(int j=0;j<adj[i].size();j++)
        {
            int x=_find(i);
            int y=_find(adj[i][j]);
            if(x==y)return 1;
            _union(x,y);
        }
    }
    return 0;
}