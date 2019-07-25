int dfs(int lft,int rgt)
{
    if(lft==rgt)return 1;
    if(s[lft]==s[rgt]&&lft+1==rgt)return 2;
    int &rt=dp[lft][rgt];
    if(~rt)return rt;
    rt=0;
    if(s[lft]==s[rgt])rt=2+dfs(lft+1,rgt-1);
    else rt=max(dfs(lft+1,rgt),dfs(lft,rgt-1));
    return rt;
}