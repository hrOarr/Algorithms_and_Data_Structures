vector<int>T[4*N+2LL],vv;
int arr[N],brr[N];
void build(int nod,int lo,int hi)
{
    if(lo==hi)
    {
        T[nod].pb(arr[lo]);
        return ;
    }
    int md=(lo+hi)>>1;
    build(2*nod,lo,md);
    build(2*nod+1,md+1,hi);
    merge(all(T[L]),all(T[R]),back_inserter(T[nod]));
}
int qry(int nod,int lo,int hi,int l,int r,int x)
{
    if(lo>r||hi<l)return 0;
    if(lo>=l&&hi<=r)
    {
        int nw=upper_bound(all(T[nod]),x)-T[nod].begin();
        return nw;
    }
    int md=(lo+hi)>>1;
    return qry(2*nod,lo,md,l,r,x)+qry(2*nod+1,md+1,hi,l,r,x);
}

int main()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>brr[i];
        vv.pb(brr[i]);
    }
    sort(all(vv));
    for(int i=1;i<=n;i++)
        arr[i]=lower_bound(all(vv),brr[i] )-vv.begin()+1;
    build(1,1,n);
    while(q--)
    {
        int l,r,x;cin>>l>>r>>x;
        int lo=1,hi=n,md,rs=-1;
        while(lo<=hi)
        {
            md=(lo+hi)>>1;
            int p=qry(1,1,n,l,r,md);
            if(p>=x)rs=md,hi=md-1;
            else lo=md+1;
        }
        cout<<vv[res-1]<<"\n";
    }
    return 0;
}
