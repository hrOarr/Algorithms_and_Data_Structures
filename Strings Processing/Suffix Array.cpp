bool cmp( int x,int y )
{
    if( rnk[x]!=rnk[y] )return rnk[x]<rnk[y];
    x += step,y += step;
    return (x<len&&y<len)?rnk[x]<rnk[y]:x>y;
}
void buildSA()
{
    for(int i=0;i<len;i++)
        SA[i] = i,rnk[i] = S[i]-'a';
    step = 1;
    while(true)
    {
        sort( SA,SA+len,cmp );
        for(int i=0;i<len-1;i++)
            tmp[i+1] = tmp[i]+cmp(SA[i],SA[i+1]);
        for(int i=0;i<len;i++)
            rnk[SA[i]] = tmp[i];
        if( tmp[len-1]==len-1 )break;
        step *= 2;
    }
}
void buildLCP()
{
    for(int i=0,k=0;i<len;i++)
    {
        if( rnk[i]==len-1 )continue;
        int j = SA[rnk[i]+1];
        while( S[i+k]==S[j+k] )++k;
        lcp[rnk[i]] = k;
        k = max(0,k-1);
    }
}
