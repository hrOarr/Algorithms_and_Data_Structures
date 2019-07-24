struct ff
{
    int cnt[2];
    ff()
    {
        memset(cnt,-1,sizeof cnt);
    }
};
int nod;
vector<ff>T;
void _insert(int x)
{
    int cur=0;
    for(int i=31;i>=0;i--)
    {
        int b=(1&(x>>i));
        if(T[cur].cnt[b]==-1)
        {
            T.pb(ff());
            T[cur].cnt[b]=nod++;
        }
        cur=T[cur].cnt[b];
    }
}
int qryMX(int x)
{
    int cur=0,rs=0;
    for(int i=31;i>=0;i--)
    {
        int b=(1&(x>>i));
        if(b==1)
        {
            if(T[cur].cnt[0]!=-1)
            {
                rs|=(1<<i);
                cur=T[cur].cnt[0];
            }
            else cur=T[cur].cnt[1];
        }
        else
        {
            if(T[cur].cnt[1]!=-1)
            {
                rs|=(1<<i);
                cur=T[cur].cnt[1];
            }
            else cur=T[cur].cnt[0];
        }
    }
    return rs;
}
int qryMN(int x)
{
    int cur=0,rs=0;
    for(int i=31;i>=0;i--)
    {
        int b=(1&(x>>i));
        if(b==1)
        {
            if(T[cur].cnt[1]!=-1)cur=T[cur].cnt[1];
            else rs|=(1<<i),cur=T[cur].cnt[0];
        }
        else
        {
            if(T[cur].cnt[0]!=-1)cur=T[cur].cnt[0];
            else rs|=(1<<i),cur=T[cur].cnt[1];
        }
    }
    return rs;
}
