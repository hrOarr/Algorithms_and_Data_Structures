void _run()
{
    for(int msk=0;msk<(1<<n);msk++)
    {
        dp[msk][-1]=Arr[msk];
        for(int i=0;i<n;i++)
        {
            if(msk&(1<<i))
                dp[msk][i]=dp[msk][i-1]+dp[msk^(1<<i)][i-1];
            else
                dp[msk][i]=dp[msk][i-1];
        }
        rs[msk]=dp[msk][n-1];
    }
    // memory optimized
    for(int i=0;i<(1<<n);i++)rs[i]=Arr[i];
    for(int i=0;i<n;i++)
    {
        for(int msk=0;msk<(1<<n);msk++)
        {
            if(msk&(1<<i))
                rs[msk]+=rs[msk^(1<<i)];
        }
    }
}