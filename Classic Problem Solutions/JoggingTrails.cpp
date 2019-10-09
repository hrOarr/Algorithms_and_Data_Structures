#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
const int N = 1e3+6,Mod = 1e9+7;
ll Dis[N][N],Hot[1<<18],n,m;

void war_shall()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if( !Dis[i][j] )
                Dis[i][j] = INT_MAX;
        }
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if( Dis[i][j]>Dis[i][k]+Dis[k][j] )
                    Dis[i][j] = Dis[i][k] + Dis[k][j];
            }
        }
    }
}

ll Chinese( int Bit )
{
    if( !Bit )return 0LL;
    ll &Ret = Hot[Bit];
    if( Ret!=-1 )return Ret;
    int i;
    for(i=1;i<=n;i++)
    {
        if( (Bit&(1<<i)) )break;
    }
    Ret = INT_MAX;
    for(int j=i+1;j<=n;j++)
    {
        int T = Bit;
        if( (Bit&(1<<i)) && (Bit&(1<<j)) )
        {
            T = (T^(1<<i));
            T = (T^(1<<j));
            Ret = min( Ret,Dis[i][j]+Chinese(T) );
        }
    }
    return Ret;
}

void Ans()
{
    int tc;cin>>tc;
    int k = 0;
    while(tc--)
    {
    cin>>n>>m;
    int Deg[n+2];
    memset( Deg,0,sizeof Deg );
    memset( Hot,-1,sizeof Hot );
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            Dis[i][j] = INT_MAX;
    }
    ll Res = 0;
    while(m--)
    {
        ll u,v,c;cin>>u>>v>>c;
        Res += c;
        Deg[u]++,Deg[v]++;
        Dis[u][v] = min( c,Dis[u][v] );
        Dis[v][u] = min( c,Dis[v][u] );
    }
    war_shall();
    int Bit = 0;
    for(int i=1;i<=n;i++)
    {
        if( Deg[i]&1 )
            Bit = (Bit^(1<<i));
    }
    Res += Chinese(Bit);
    cout<< "Case "<<++k<< ": "<<Res<< "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Ans();

    return 0;
}
