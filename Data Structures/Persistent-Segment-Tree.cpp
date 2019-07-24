struct lol
{
    int sm,lft,rgt;
}T[N*20];
int A[N],rt[N],now,cur;
int updt(int pre,int lo,int hi,int id,int x)
{
    ++now;
    int nod=now;
    T[nod]=T[pre];
    if(lo==hi)
    {
        T[nod].sm+=x;
        return nod;
    }
    int md=(lo+hi)>>1;
    if(id<=md)T[nod].lft=updt(T[nod].lft,lo,md,id,x);
    else T[nod].rgt=updt(T[nod].rgt,md+1,hi,id,x);
    T[nod].sm=(T[T[nod].lft].sm+T[T[nod].rgt].sm);
    return nod;
}
int qry(int nod,int lo,int hi,int l,int r)
{
    if(lo>r||hi<l)return 0;
    if(lo>=l&&hi<=r)return T[nod].sm;
    int md=(lo+hi)>>1;
    int r1=qry(T[nod].lft,lo,md,l,r);
    int r2=qry(T[nod].rgt,md+1,hi,l,r);
    return (r1+r2);
}
