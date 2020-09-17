struct ff
{
    int l,r,ps;
}A[N];
bool cmp(ff x,ff y)
{
    if((x.l/block)!=(y.l/block))return (x.l/block)<(y.l/block);
    return x.r<y.r;
}
void _add(int ps)
{
    M[B[ps]]+=1;
    if(M[B[ps]]==1)cnt++;
}
void _rem(int ps)
{
    --M[B[ps]];
    if(!M[B[ps]])cnt--;
}
int main()
{
    block=sqrt(n);
    sort(A+1,A+q+1,cmp);
    int curL=0,curR=0;
    for(int i=1;i<=q;i++)
    {
        int l=A[i].l,r=A[i].r;
        while(curL<l)_rem(curL++);
        while(curL>l)_add(--curL);
	while(curR<r)_add(++curR);
	while(curR>r)_rem(curR--);
        rs[A[i].ps]=cnt;
    }

    return 0;
}
