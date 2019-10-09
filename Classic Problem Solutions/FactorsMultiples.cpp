#include "bits/stdc++.h"
using namespace std;

const int N = 1e2+4,inf = 1e9;
typedef long long int ll;
vector<int>Vec[N];
int Vis[N],Pair[N],Cnt,n,m;

bool dfs( int u )
{
    for(int i=0;i<Vec[u].size();i++)
    {
        int v = Vec[u][i];
        if( Vis[v] )continue;
        Vis[v] = 1;
        if( !Pair[v] || dfs(Pair[v]) )
        {
            Pair[v] = u;
            return true;
        }
    }
    return false;
}

void bpm()
{
    for(int i=1;i<=n;i++)
    {
        memset( Vis,0,sizeof Vis );
        if( dfs(i) )Cnt++;
    }
}

int main()
{
    int tc,k=0;cin>>tc;
    while(tc--)
    {
    for(int i=0;i<N;i++)Vec[i].clear(),Pair[i]=0;
    Cnt = 0;cin>>n;
    ll Arr[n+2];
    for(int i=1;i<=n;i++)cin>>Arr[i];
    cin>>m;
    ll Brr[m+2];
    for(int j=1;j<=m;j++)cin>>Brr[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if( Brr[j]%Arr[i]==0 )
            {
                Vec[i].push_back(j);
               // Vec[j].push_back(i);
            }
        }
    }
    bpm();
    cout<< "Case "<<++k<< ": "<<Cnt<< "\n";
    }


    return 0;
}
