void push_down(int nod,int st,int ed,int vl)
{
    T[nod]+=(ed-st+1)*vl;
    if(st!=ed)
    {
        lz[2*nod]+=vl;
        lz[2*nod+1]+=vl;
    }
    lz[nod]=0;
}
void updt(int nod,int st,int ed,int l,int r,int vl)
{
    if(lz[nod])push_down(nod,st,ed,lz[nod]);
    if(st>ed||st>r||ed<l)return;
    if(st>=l&&ed<=r)
    {
        T[nod]+=(ed-st+1)*vl;
        if(st!=ed)
        {
            lz[2*nod]+=vl;
            lz[2*nod+1]+=vl;
        }
        return;
    }
    int md=(st+ed)>>1;
    updt(2*nod,s,md,l,r,vl);
    updt(2*nod+1,md+1,ed,l,r,vl);
    T[nod]=T[2*nod]+T[2*nod+1];
}
int qry(int nod,int s,int ed,int l,int r)
{
    if(st>ed||st>r||ed<l)return 0;
    if(lz[nod])push_down(nod,st,ed,lz[nod]);
    if(st>=l&&ed<=r)return T[nod];
    int md=(st+ed)>>1;
    return qry(2*nod,st,md,l,r)+qry(2*nod+1,md+1,ed,l,r);
}
