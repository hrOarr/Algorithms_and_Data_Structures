#include "bits/stdc++.h"
using namespace std;

#define  F  first
#define  S  second
#define  mp make_pair
typedef long long int ll;
const int N = 2e5+6,inf = 1e9+7;
set<int>st[N];
int Arr[N],siz[N],zro[21],nzro[21],n,Nod;
bool vis[N];
ll Res;
void dfs( int u,int p )
{
    Nod++;
    siz[u] = 1;
    for(auto v:st[u])
    {
        if( v==p||vis[v] )continue;
        dfs(v,u);
        siz[u] += siz[v];
    }
}

int centroid( int u,int p )
{
    for(auto v:st[u])
    {
        if( v==p||siz[v]<=Nod/2||vis[v] )
            continue;
        return centroid(v,u);
    }
    return u;
}

void Add( int u,int p,ll xr )
{
    xr ^= Arr[u];
    for(int i=20;i>=0;i--)
    {
        if(xr&(1<<i))nzro[i]++;
        else zro[i]++;
    }
    for(auto v:st[u])
    {
        if( v==p||vis[v] )
            continue;
        Add(v,u,xr);
    }
}

void Cal( int u,int p,ll xr )
{
    xr ^= Arr[u];
    for(int i=20;i>=0;i--)
    {
        if(xr&(1<<i))Res+=(1<<i)*(zro[i]*1LL);
        else Res+=(1<<i)*(nzro[i]*1LL);
    }
    for(auto v:st[u])
    {
        if( v==p||vis[v] )
            continue;
        Cal(v,u,xr);
    }
}

void Decomposed( int u,int p )
{
    Nod = 0;
    dfs(u,u);
    int rt = centroid(u,u);
    vis[rt] = true;
    for(int i=20;i>=0;i--)
    {
        if(Arr[rt]&(1<<i))nzro[i]++;
        else zro[i]++;
    }
    for(auto v:st[rt])
    {
        if( vis[v] )continue;
        Cal(v,rt,0);
        Add(v,rt,Arr[rt]);
    }
    for(int i=0;i<=20;i++)
        zro[i] = nzro[i] = 0;
    for(auto v:st[rt])
    {
        if( v==p||vis[v] )
            continue;
        Decomposed(v,rt);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>Arr[i],Res+=Arr[i];
    int m = n-1;
    while(m--)
    {
        int u,v;cin>>u>>v;
        st[u].insert(v);
        st[v].insert(u);
    }
    Decomposed(1,-1);
    cout<<Res<< "\n";

    return 0;
}
