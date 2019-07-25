void _print(int st)
{
    if(dir[st]==-1)return;
    _print(dir[st]);
    cout<<A[st]<<" ";
}
int dfs(int u)
{
    int &rt=dp[u];
    if(~rt)return rt;
    int mx=0;
    for(int v=u+1;v<=n;v++)
    {
        if(A[v]>A[u]&&dfs(v)>mx)
            mx=dfs(v),dir[u]=v;
    }
    return rt=1+mx;
}
int main()
{
    for(int i=1;i<=n;i++)
    {
        if(dfs(i)>mx)
            mx=dfs(i),st=i;
    }
}
