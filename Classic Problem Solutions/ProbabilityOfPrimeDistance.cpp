#include "bits/stdc++.h"
using namespace std;

#define  F  first
#define  S  second
#define  pb push_back
#define  mp make_pair
typedef long long int ll;
const int N = 2e5+5;
vector<int>st[N];
map<int,ll>M;
int Child[N],Centroid[N],vis[N];
ll Nod,Cnt[20][N],Res;
int Arr[N],Prim[N],id;
void dfs( int u,int p )
{
    Child[u] = 1;
    ++Nod;
    for(auto v:st[u])
    {
        if( v==p||Centroid[v] )
            continue;
        dfs(v,u);
        Child[u] += Child[v];
    }
}
void Add( int u,int p,int lev,int dis )
{
    Cnt[lev][dis]++;
    for(auto v:st[u])
    {
        if(v==p||Centroid[v])
            continue;
        Add(v,u,lev,dis+1);
    }
}
void Rem( int u,int p,int lev,int dis )
{
    Cnt[lev][dis]--;
    for(auto v:st[u])
    {
        if(v==p||Centroid[v])
            continue;
        Rem(v,u,lev,dis+1);
    }
}
ll Cal( int u,int p,int lev,int dis )
{
    ll Ret = 0;
    for(int i=1;i<=id;i++)
    {
        if( Prim[i]-dis<0 )continue;
        if( !Cnt[lev][Prim[i]-dis] )break;
        if( Prim[i]!=dis )
            Ret += Cnt[lev][Prim[i]-dis];
        else
            Ret += 2*Cnt[lev][Prim[i]-dis];
    }
    for(auto v:st[u])
    {
        if(v==p||Centroid[v])
            continue;
        Ret += Cal(v,u,lev,dis+1);
    }
    return Ret;
}
int Find_centroid( int u,int p )
{
    bool F = true;
    int id = 0;
    for(auto v:st[u])
    {
        if( v==p||Centroid[v] )
            continue;
        if( Child[v]>Nod/2 )
            F = false;
        if(!id || Child[v]>Child[id])
            id = v;
    }
    if( F && (Nod-Child[u])<=Nod/2 )
        return u;
    return Find_centroid(id,u);
}

void Get_centroid(int u,int p,int lev)
{
    Nod = 0;
    dfs(u,p);
    int root = Find_centroid(u,p);
    Centroid[root] = true;
    Add(root,p,lev,0);
    ll Now = 0;
    for(auto v:st[root])
    {
        if( Centroid[v] )
            continue;
        Rem(v,root,lev,1);
        Now += Cal(v,root,lev,1);
        Add(v,root,lev,1);
    }
    Res += Now/2;
    for(auto v:st[root])
    {
        if(v==p||Centroid[v])
            continue;
        Get_centroid(v,root,lev+1);
    }
    for(int i=0;i<N&&Cnt[lev][i];i++)
        Cnt[lev][i] = 0;
}
void Seive()
{
    vis[0] = vis[1] = 1;
    for(int i=4;i<N;i+=2)vis[i] = 1;
    for(int i=3;i*i<=N;i+=2)
    {
        if(!vis[i])
        {
            for(int j=i*i;j<=N;j+=(i+i))
                vis[j] = 1;
        }
    }
    for(int i=1;i<=50000;i++)
    {
        if(!vis[i])Prim[++id] = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Seive();
    ll n;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u,v;cin>>u>>v;
        st[u].push_back(v);
        st[v].push_back(u);
    }
    Get_centroid(1,-1,1);
    ll now = (n*(n-1))/2LL;
    cout<<fixed;
    cout<<setprecision(6);
    cout<<(double)Res/now<< "\n";


    return 0;
}
