int dfs(int ps,int sm)
{
    if(ps>=k)return (sm==0); // k is equal to coin Array size
    int &rt=dp[ps][sm];
    if(~rt)return rt;
    int r1=0,r2=0;
    if(sm-coin[ps]>=0)r1=dfs(ps,sm-coin[ps]);
    r2=dfs(ps+1,sm);
    return rt=r1|r2;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int n;cin>>n;
    cout<<dfs(0,n)<<"\n";
}
