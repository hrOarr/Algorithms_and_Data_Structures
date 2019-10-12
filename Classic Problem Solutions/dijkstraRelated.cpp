//1 v — find the length of shortest path from vertex 1 to vertex v.
//2 c l1 l2 ... lc — add 1 to weights of edges with indices l1, l2, ..., lc.

#include"bits/stdc++.h"
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
typedef long long int ll;
const ll N=1e6+2,inf=1e9+7;
void _run();
void no(){cout<<"No\n",exit(0);}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	_run();
	return 0;
}
vector<pair<int,pair<int,int> > >vec[N];
vector<int>vec2[N];
vector<pair<int,pair<int,int> > >edg;
ll tim,n,m,q,found[N],rs[N],dis[N],dis2[N],vs[N],tmp[N];
void dijkstra(int s)
{
    for(int i=1;i<=n;i++)dis[i]=inf*inf;
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
	pq.push(mp(0,s)); // mp=make_pair
	dis[s]=0;
	while(!pq.empty())
    {
		auto rt=pq.top();pq.pop();
		ll d=rt.fs,u=rt.sc;
		vs[u]=1;
		if(d>dis[u])continue;
		for(auto x:vec[u])
		{
			if(dis[u]+x.sc.fs<dis[x.fs])
			{
				dis[x.fs]=dis[u]+x.sc.fs;
				pq.push(make_pair(dis[x.fs],x.fs));
			}
		}
	}
	for(int i=1;i<=m;i++)
        tmp[i]=dis[edg[i-1].sc.fs]-dis[edg[i-1].sc.sc]+edg[i-1].fs;
    for(int i=1;i<=n;i++)
        rs[i]=dis[i];
}
void _updt()
{
    for(int i=0;i<=n;i++)vec2[i].clear();
    for(int i=1;i<=n;i++)dis2[i]=n;
    vec2[0].pb(1);dis2[1]=0;++tim;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(int)vec2[i].size();j++)
        {
            int u=vec2[i][j];
            if(found[u]==tim)continue;
            found[u]=tim;
            for(auto x:vec[u])
            {
                if(dis2[x.fs]>i+tmp[x.sc.sc])
                {
                   // cout<<u<<" "<<x.fs<<" "<<x.sc.sc<<"*\n";
                    dis2[x.fs]=i+tmp[x.sc.sc];
                    vec2[i+tmp[x.sc.sc]].pb(x.fs);
                }
            }
        }
    }
   // for(int i=1;i<=n;i++)cout<<i<<": "<<dis2[i]<<"\n";
    for(int i=1;i<=m;i++)
        tmp[i]+=dis2[edg[i-1].sc.fs]-dis2[edg[i-1].sc.sc];
    for(int i=1;i<=n;i++)
        rs[i]+=dis2[i];
}
void _run()
{
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        int u,v,c;cin>>u>>v>>c;
        edg.pb(mp(c,mp(u,v)));
        vec[u].pb(mp(v,mp(c,i)));
        //vec[v].pb(mp(u,mp(c,i)));
    }
    dijkstra(1);
    //for(int i=1;i<=n;i++)cout<<i<<": "<<dis[i]<<"\n";
    while(q--)
    {
        int typ;cin>>typ;
        if(typ==1)
        {
            int v;cin>>v;
            if(vs[v])cout<<rs[v]<<"\n";
            else cout<<"-1\n";
        }
        else
        {
            int p;cin>>p;
            while(p--)
            {
                int x;cin>>x;//x--;
                tmp[x]++;
            }
            _updt();
        }
    }
}
