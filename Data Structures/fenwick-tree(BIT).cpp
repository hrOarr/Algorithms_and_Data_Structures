int qry(int T[],int id)
{
    int rt=0;id=id+1;
    while(id>0)
    {
        rt+=T[id];
        id-=id&(-id);
    }
    return rt;
}
void updtBIT(int T[],int n,int id,int vl)
{
    id=id+1;
    while(id<=n)
    {
        T[id]+=vl;
        id+=id&(-id);
    }
}
int sum(int x,int T1[],int T2[])
{
    return (qry(T1,x)*x)-qry(T2,x);
}
void updtRange(int T1[],int T2[],int n,int vl,int l,int r)
{
    updtBIT(T1,n,l,vl);
    updtBIT(T1,n,r+1,-vl);
    updtBIT(T2,n,l,vl*(l-1));
    updtBIT(T2,n,r+1,-vl*r);
}
int rangeSum(int l,int r,int T1[],int T2[])
{
    return sum(r,T1,T2)-sum(l-1,T1,T2);
}
