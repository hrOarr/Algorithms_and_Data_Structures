
    for(int i=0;i<n;i++)tbl[i][0]=Arr[i];
    for(int j=1;j<=k;j++)
    {
        for(int i=0; i<=n-(1<<j);i++)
            tbl[i][j]=min(tbl[i][j-1],tbl[i+(1<<(j-1))][j-1]);
    }

    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        int rs=inf;
        for(int j=k;j>=0;j--)
        {
            if(l+(1<<j)-1<=r)
            {
                rs=min(rs,tbl[l][j]);
                l+=(1<<j);
            }
        }
        cout<<rs<<"\n";
    }

    // O(1)
    int log[MAXN+1];log[1] = 0;
    for(int i=2;i<=MAXN;i++)log[i]=log[i/2]+1;
    int j=log[R-L+1];
    int rs=min(tbl[L][j],tbl[R-(1<<j)+1][j]);
