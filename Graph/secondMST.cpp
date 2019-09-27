#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef pair <ll,ll> pp;
const ll N = 200010, inf = 112233445566778;

struct lol {
    ll mx;
};
lol a1[20][N];

pair <pp,pp> p1[N];
vector <pair<ll,ll> > v1[N];
pair <ll,pp> p2[N];
ll par[N],vis[N],n,m;
ll tbl[20][N],lev[N];
ll _find( ll x ) {
    if (x == par[x]) return x;
    return par[x] = _find(par[x]);
}

void _union(ll x, ll y) {
    ll u = _find(x);
    ll v = _find(y);
    if (u != v) par[u] = v;
    return;
}

ll _mst() {
    ll x = 0;
    for (ll i = 1; i <= m; i ++) {
        ll u = p1[i].second.first;
        ll v = p1[i].second.second;
        ll w = p1[i].first.first;
        ll id = p1[i].first.second;
        if ( _find(u) != _find(v) ) {
            x += w, vis[id] ++;
            _union(u,v);
            v1[u].push_back({v,w});
            v1[v].push_back({u,w});
        }
    }
    return x;
}

void _dfs(ll u, ll par, ll l) {
    tbl[0][u] = par;
    lev[u] = l;
    for (ll i = 0; i < v1[u].size(); i ++) {
        ll v = v1[u][i].first;
        ll w = v1[u][i].second;
        if ( !lev[v] ) {
            a1[0][v].mx = w;
            _dfs( v,u,l+1 );
        }
    }
}

void _sprse() {
    for (ll j = 1; j < 20; j ++) {
        for (ll i = 1; i <= n; i ++) {
            if ( tbl[j-1][i] != -1 ) {
                a1[j][i].mx = max( a1[j-1][i].mx,a1[j-1][tbl[j-1][i]].mx );
                tbl[j][i] = tbl[ j-1 ][ tbl[j-1][i] ];
            }
        }
    }
}

ll _lca(ll u, ll v) {
    ll mx = -inf;
    if ( lev[u] < lev[v] ) swap(u,v);
    for (ll i = 19; i >= 0; i --) {
        if ( (lev[u]-(1<<i)) >= lev[v] ) {
            mx = max( mx,a1[i][u].mx );
            u = tbl[i][u];
        }
    }
    if (u == v) return mx;
    for (ll i = 19; i >= 0; i --) {
        if ( tbl[i][u] != tbl[i][v] && tbl[i][u] != -1 ) {
            mx = max( mx,a1[i][u].mx );
            mx = max( mx,a1[i][v].mx );
            u = tbl[i][u];
            v = tbl[i][v];
        }
    }
    mx = max( mx,a1[0][u].mx );
    mx = max( mx,a1[0][v].mx );
    return mx;
}

int main() {
    cin >> n >> m;
    for (ll i = 1; i <= m; i ++) {
        ll a,b,c;
        cin >> a >> b >> c;
        p1[i] = { {c,i},{a,b} };
        p2[i] = { c,{a,b} };
    }
    sort( p1+1,p1+m+1 );
    for (ll i = 0; i <= n; i ++) {
        par[i] = i;
    }
    ll cost = _mst();
    memset(tbl, -1, sizeof tbl);
    for (ll i = 0; i < 20; i ++) {
        for (ll j = 0; j <= n; j ++) {
            a1[i][j].mx = -inf;
        }
    }
    _dfs( 1LL,-1LL,1LL );
    _sprse();
    for (ll i = 1; i <= m; i ++) {
        if ( vis[i] ) cout << cost << "\n";
        else {
            ll w = p2[i].first;
            ll u = p2[i].second.first, v = p2[i].second.second;
            ll mx = _lca( u,v );
            cout << (cost+w-mx) << "\n";
        }
    }


    return 0;
}
