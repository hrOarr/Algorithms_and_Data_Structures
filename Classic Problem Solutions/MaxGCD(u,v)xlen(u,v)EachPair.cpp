#include <bits/stdc++.h>

#define REP(i, n)	for(ll i=0;i<n;i++)
#define REPN(i, n)	for(ll i=1;i<=n;i++)
#define SET(i, n)	memset(i, n, sizeof(i))

#define MAX			100050
#define INF			(1 << 28)
#define pb			push_back

using namespace std;

typedef long long ll;

ll n, nn, dp[MAX], vis[MAX], ret, sub[MAX];
vector<ll>edge[MAX], cost[MAX], factors[MAX];

void dfs1(ll at, ll past){
	sub[at] = 1; nn++;
	REP(i, edge[at].size()){
		ll u = edge[at][i];
		if(vis[u] || u == past) continue;
		dfs1(u, at);
		sub[at] += sub[u];
	}
}

ll dfs2(ll at, ll past){
	REP(i, edge[at].size()){
		ll u = edge[at][i];
		if(vis[u] || u == past) continue;
		if(sub[u] > nn / 2) return dfs2(u, at);
	}
	return at;
}

void solve(ll at, ll past, ll g, ll len){
	REP(i, factors[g].size()){
		ll u = factors[g][i];
		ret = max(ret, u * (len + dp[u]));
	}
	REP(i, edge[at].size()){
		ll u = edge[at][i];
		ll c = cost[at][i];
		if(vis[u] || u == past) continue;
		solve(u, at, __gcd(g, c), len + 1);
	}
}

void add(ll at, ll past, ll g, ll len){
	REP(i, factors[g].size()){
		ll x = factors[g][i];
		dp[x] = max(dp[x], len);
	}
	REP(i, edge[at].size()){
		ll u = edge[at][i];
		ll c = cost[at][i];
		if(vis[u] || u == past) continue;
		add(u, at, __gcd(g, c), len + 1);
	}
}

void remove(ll at, ll past, ll g, ll len){
	REP(i, factors[g].size()){
		ll x = factors[g][i];
		dp[x] = 0;
	}
	REP(i, edge[at].size()){
		ll u = edge[at][i];
		ll c = cost[at][i];
		if(vis[u] || u == past) continue;
		remove(u, at, __gcd(g, c), len + 1);
	}
}

void decompose(ll at){
	nn = 0;
	dfs1(at, at);
	ll u = dfs2(at, at);
	vis[u] = 1;
	// cout << "CENTROID -> " << u << endl;
	REP(i, edge[u].size()){
		ll v = edge[u][i];
		ll c = cost[u][i];
		if(vis[v]) continue;
		solve(v, u, c, 1);
		add(v, u, c, 1);
	}
	remove(u, u, 0, 0);
	REP(i, edge[u].size()){
		ll v = edge[u][i];
		if(vis[v]) continue;
		decompose(v);
	}
}

void reset(){
	SET(vis, 0);
	SET(dp, 0);
	ret = 0;
	REP(i, MAX){
		edge[i].clear();
		cost[i].clear();
	}
}

void init(){
	for(ll i=1;i<MAX;i++){
		for(ll j=i;j<MAX;j+=i){
			factors[j].pb(i);
		}
	}
}

int main(){
	init();
	ll tc, x, y, c;
	scanf("%lld", &tc);
	while(tc--){
		reset();
		scanf("%lld", &n);
		REP(i, n-1){
			scanf("%lld %lld %lld", &x, &y, &c);
			edge[x].pb(y);
			edge[y].pb(x);
			cost[x].pb(c);
			cost[y].pb(c);
		}
		ret = 1;
		decompose(1);
		printf("%lld\n", ret);
	}
	return 0;
}
