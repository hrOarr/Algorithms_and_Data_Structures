// range query and point update

void process()
{
    int blck_id=-1,blck=sqrt(n);
    for(int i=0;i<n;i++)
    {
        if(!(i%blck))
            blck_id++;
        block[blck_id]+=A[i];
    }
}
int qry(int l,int r)
{
    int rt=0;
    while(l<r&&(l%blck)&&l)rt+=A[l++];
    while(l+blck<=r)rt+=block[l/blck],l+=blck;
    while(l<=r)rt+=A[l++];
    return rt;
}
void updt(int idx,int vl)
{
    block[idx/blck]+=(vl-A[idx]);
    A[idx]=vl;
}
