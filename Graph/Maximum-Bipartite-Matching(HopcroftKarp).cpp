vector<int>vec[N];
int lft,rgt,pairU[N],pairV[N],dis[N];
bool bfs()
{
    queue<int>q1;
    for(int i=1;i<=lft;i++)
    {
        if(!pairU[i])dis[i]=0,q1.push(i);
        else dis[i]=inf;
    }
    dis[0]=inf;
    while(!q1.empty())
    {
        int u=q1.front();q1.pop();
        if(dis[u]<dis[0])
        {
            for(auto v:vec[u])
            {
                if(dis[pairV[v]]==inf)
                {
                    dis[pairV[v]]=dis[u]+1;
                    q1.push(pairV[v]);
                }
            }
        }
    }
    return (dis[0]!=inf);
}
bool dfs(int u)
{
    if(u!=0)
    {
        for(auto v:vec[u])
        {
            if(dis[pairV[v]]==dis[u]+1)
            {
                if(dfs(pairV[v]))
                {
                    pairU[u]=v;
                    pairV[v]=u;
                    return true;
                }
            }
        }
        dis[u]=inf;
        return false;
    }
    return true;
}
int _hopcroft()
{
    lft=rgt=n;
    for(int i=0;i<=lft;i++)pairU[i]=0;
    for(int i=0;i<=rgt;i++)pairV[i]=0;
    int rs=0;
    while(bfs())
    {
        for(int i=1;i<=lft;i++)
        {
            if(!pairU[i]&&dfs(i))rs++;
        }
    }
    return rs;
}