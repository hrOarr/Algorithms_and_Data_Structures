/*
It is well known that Berland has n cities, which form the Silver ring — cities i and i?+?1 (1?=?i?<?n) are connected by a road, as well as the cities n and 1. The goverment have decided to build m new roads. The list of the roads to build was prepared. Each road will connect two cities. Each road should be a curve which lies inside or outside the ring. New roads will have no common points with the ring (except the endpoints of the road).

Now the designers of the constructing plan wonder if it is possible to build the roads in such a way that no two roads intersect (note that the roads may intersect at their endpoints). If it is possible to do, which roads should be inside the ring, and which should be outside?
*/

#include "bits/stdc++.h"
using namespace std;
const int N = 1e5;
bool col[N],vis[N];
int X[N],Y[N],cmp[N],MX,com;
vector<int> vv[N],rev[N],top;
void dfs(int u)
{
    vis[u]=true;
    for(int i=0;i<vv[u].size();i++)
    {
        int v=vv[u][i];
        if(!vis[v])dfs(v);
    }
    top.push_back(u);
}

void dfs1(int u)
{
    vis[u]=true;
    if(u<=MX)col[u]=1;
    else col[u-MX]=0;
    cmp[u]=com;
    for(int i=0;i<rev[u].size();i++)
    {
        int v=rev[u][i];
        if(!vis[v])dfs1(v);
    }
}

bool intrsect(int l,int r)
{
    int lf=min(X[l],X[r]);
    int rg=max(Y[l],Y[r]);
    if(lf==X[l]&&rg==Y[l])return true;
    if(lf==X[r]&&rg==Y[r])return true;
    int mn=min(Y[l],Y[r]);
    int mx=max(X[l],X[r]);
    if(mn<=mx)return true;
    return false;
}

int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>X[i]>>Y[i];
        if(X[i]>Y[i])swap(X[i],Y[i]);
    }
    MX=m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==j)continue;
            bool ok=intrsect(i,j);
            if(ok)continue;
            vv[i].push_back(j+m);
            vv[j].push_back(i+m);
            vv[i+m].push_back(j);
            vv[j+m].push_back(i);

            rev[i].push_back(j+m);
            rev[j].push_back(i+m);
            rev[i+m].push_back(j);
            rev[j+m].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i);
    }
    memset(vis,0,sizeof vis);
    reverse(top.begin(),top.end());
    for(int i=0;i<top.size();i++)
    {
        if(!vis[top[i]])com++,dfs1(top[i]);
    }
    for(int i=1;i<=m;i++)
    {
        if(cmp[i]==cmp[i+m])
        {
            cout<<"Impossible\n";
            exit(0);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(col[i])cout<<"i";
        else cout<<"o";
    }
    cout<< "\n";


    return 0;
}
