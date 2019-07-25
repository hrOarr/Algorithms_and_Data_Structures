void sievephi(int n)
{
    for(int i=1; i<=n; i++)phi[i]=i;
    phi[1]=prim[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(!prim[i])
        {
            for(int j=i;j<=n; j+=i)
            {
                prim[j+i]=1;
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}

// using factorization
int phi(int n)
{
    int rs=n;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)n/=i;
            rs-=rs/i;
        }
    }
    if(n>1)rs-=rs/n;
    return rs;
}
