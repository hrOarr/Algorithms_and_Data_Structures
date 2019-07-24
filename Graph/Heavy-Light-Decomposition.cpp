void dfs( int u,int p,int lev )
{
    Par[u] = p;
    Dep[u] = lev;
    Child[u] = 1;
    for(int v:vec[u])
    {
        if( v==p )
            continue;
        dfs( v,u,lev+1 );
        Child[u] += Child[v];
    }
}
void HLD( int u,int p )
{
    if( Head[Now]==-1 )
        Head[Now] = u;
    Chain[u] = Now;
    st[u] = ++tim;
    int id = -1;
    for(int v:vec[u])
    {
        if( v==p )
            continue;
        if( id==-1 || Child[id]<Child[v] )
            id = v;
    }
    if( id!=-1 )
        HLD( id,u );
    for(int v:vec[u])
    {
        if( v==p || v==id )
            continue;
        ++Now;
        HLD( v,u );
    }
}
int lca( int u,int v )
{
    while( Head[ Chain[u] ]!=Head[ Chain[v] ] )
    {
        if( Dep[ Head[ Chain[u] ] ]<Dep[ Head[ Chain[v] ] ] )
            v = Par[Head[ Chain[v] ]];
        else
            u = Par[Head[ Chain[u] ]];
    }
    return (Dep[u]>Dep[v])?v:u;
}
void Updt( int Nod,int lo,int hi,int id,int vl )
{
    if( hi<id || lo>id )
        return ;
    if( lo==hi )
    {
        T[Nod] = vl;
        return ;
    }
    int mid = (lo+hi)>>1;
    Updt( 2*Nod,lo,mid,id,vl );
    Updt( 2*Nod+1,mid+1,hi,id,vl );
    T[Nod] = max( T[2*Nod],T[2*Nod+1] );
}
int Qry( int Nod,int lo,int hi,int l,int r )
{
    if( hi<l || lo>r )
        return 0;
    if( lo>=l&&hi<=r )
        return T[Nod];
    int mid = (lo+hi)>>1;
    return max( Qry(2*Nod,lo,mid,l,r),Qry(2*Nod+1,mid+1,hi,l,r) );
}
int Process( int u,int v )
{
    int Ret = 0;
    while(true)
    {
        if( Chain[u]==Chain[v] )//return Ret;
            return max(Ret,Qry(1,1,n,st[v],st[u]));
        Ret = max( Ret,Qry(1,1,n,st[Head[Chain[u]]],st[u]) );
        u = Par[ Head[ Chain[u] ] ];
    }
    return Ret;
}