bool Ok(int x,int y)
{
    return (x>=0&&x<n&&y>=0&&y<m);
}
int dfs(int l,int r)
{
    if(!Ok(l,r))return 0;
    int &rt=dp[l][r];
    if(~rt)return rt;
    rt=-inf;
    rt=max(rt,dfs(l+1,r)+A[l][r]);
    rt=max(rt,dfs(l+1,r-1)+A[l][r]);
    rt=max(rt,dfs(l+1,r+1)+A[l][r]);
    return rt;
}
int main()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>A[i][j];
    cout<<dfs(0,0)<<"\n";
}
