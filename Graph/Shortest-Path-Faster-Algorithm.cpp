// minimum number of steps to reach (1,1) to (n,m) in 2D grid
#include "bits/stdc++.h"
using namespace std;
#define  F  first
#define  S  second
#define  pb push_back
#define  mp make_pair
typedef long long int ll;
const int N=1e4+6,inf=1e9+7;
int n,m,k,dis[N],vis[N];
pair<int,int>P[N];
int _spfa()
{
    for(int i=1;i<=k;i++)
        dis[i]=inf,vis[i]=0;
    queue<int>q1;q1.push(1);vis[1]=1;
    dis[1]=0;
    while(!q1.empty())
    {
        int u=q1.front();q1.pop();
        for(int v=1;v<=k;v++)
        {
            int cur=abs(P[u].F-P[v].F)+abs(P[u].S-P[v].S);
            int vl=inf;
            if(cur<=1)vl=0;
            else if(abs(P[u].F-P[v].F)<=2||abs(P[u].S-P[v].S)<=2)vl=1;
            if(dis[v]>dis[u]+vl)
            {
                dis[v]=dis[u]+vl;
                if(!vis[v])
                    vis[v]=1,q1.push(v);
            }
        }
        vis[u]=0;
    }
    if(dis[k]==inf)return -1;
    return dis[k];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;bool flg=0;
    for(int i=1;i<=k;i++)
    {
        cin>>P[i].F>>P[i].S;
        if(P[i].F==n&&P[i].S==m)
            flg=1;
    }
    if(flg==0)P[++k]=mp(n+1,m+1);
    cout<<_spfa()<< "\n";


    return 0;
}
