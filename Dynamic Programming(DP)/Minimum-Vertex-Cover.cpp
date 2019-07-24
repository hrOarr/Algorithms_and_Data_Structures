int dfs(int u,int f)
{
    int &rt=dp[u][f];
    if(~rt)return rt;
    int cur=0;
    for(auto v:vec[u])
    {
        if(pr[u]!=v)
        {
            pr[v]=u;
            if(!f)cur+=dfs(v,1);
            else cur+=min(dfs(v,1),dfs(v,0));
        }
    }
    return rt=cur+f;
}

