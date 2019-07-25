int dfs(int l,int r)
{
    if(l==s1.size()||r==s2.size())return 0;
    int &rt=dp[l][r];
    if(~rt)return rt;
    rt=0;
    if(s1[l]==s2[r])rt=1+dfs(l+1,r+1);
    else rt=max(dfs(l+1,r),dfs(l,r+1));
    return rt;
}
// unique solution print
string rs;
void _print(int l,int r)
{
    if(l==s1.size()||r==s2.size())
    {
        cout<<rs<<"\n";
        return;
    }
    if(s1[l]==s2[r])
    {
        rs+=s1[l];
        _print(l+1,r+1);
    }
    else
    {
        if(dp[l+1][r]>dp[l][r+1])_print(l+1,r);
        else _print(l,r+1);
    }
}
// multilple solutions (backtracking)
string rs;
void _print(int l,int r)
{
    if(l==s1.size()||r==s2.size())
    {
        cout<<rs<<"\n";
        return;
    }
    if(s1[l]==s2[r])
    {
        rs+=s1[l];
        _print(l+1,r+1);
        rs.erase(rs.end()-1);
    }
    else
    {
        if(dp[l+1][r]>dp[l][r+1])_print(l+1,r);
        else if(dp[l+1][r]<dp[l][r+1])_print(l,r+1);
        else _print(l+1,r),_print(l,r+1);
    }
}
