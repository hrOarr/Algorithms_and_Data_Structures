void updt(int id,int vl)
{
    while(id<N)T[id]+=vl,id+=(id&-id);
}
int qry(int id)
{
    int rt=0;
    while(id>0)rt+=(T[id]),id-=(id&-id);
    return rt;
}