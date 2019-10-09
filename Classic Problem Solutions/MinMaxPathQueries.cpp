#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
const ll N = 100010, lg = 16;
const ll inf = 11223344556;

struct fat
{
    ll mn, mx;
};
fat a1[lg+2][N];
vector < pair<ll,ll> > v1[N];
ll par[N],tbl[lg+2][N];
ll dep[N],n,m,q;
ll mn1, mx1;

void dfs(ll u, ll pa, ll lev, ll w)
{
    tbl[0][u] = pa;
    dep[u] = lev;
    for (int i = 0; i < v1[u].size(); i ++){
        ll v = v1[u][i].first, w = v1[u][i].second;
        if (dep[v] == -1){
            a1[0][v].mn = w;
            a1[0][v].mx = w;
            dfs(v, u, lev + 1, w);
        }
    }
}

void sprs_tbl()
{
    for (int i = 1; i <= lg; i ++){
        for (int j = 0; j < n; j ++){
            if (tbl[i-1][j] != -1){
                 a1[i][j].mn = min(a1[i-1][j].mn, a1[i-1][ tbl[i-1][j] ].mn);
                 a1[i][j].mx = max(a1[i-1][j].mx, a1[i-1][ tbl[i-1][j] ].mx);
                 tbl[i][j] = tbl[i-1][ tbl[i-1][j] ];
            }
        }
    }
}

void _lca(ll u, ll v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = lg; i >= 0; i --){
         if (dep[u] - (1 << i) >= dep[v]){
              mn1 = min(mn1, a1[i][u].mn);
              mx1 = max(mx1, a1[i][u].mx);
              u = tbl[i][u];
         }
    }
    if (u == v) return;
    int i;
    for (i = lg; i >= 0; i --){
        if (tbl[i][u] != -1 && tbl[i][u] != tbl[i][v]){
            mn1 = min(mn1, a1[i][u].mn);
            mn1 = min(mn1, a1[i][v].mn);
            mx1 = max(mx1, a1[i][u].mx);
            mx1 = max(mx1, a1[i][v].mx);
            u = tbl[i][u], v = tbl[i][v];
        }
    }

    mn1 = min(mn1, a1[0][u].mn);
    mn1 = min(mn1, a1[0][v].mn);
    mx1 = max(mx1, a1[0][u].mx);
    mx1 = max(mx1, a1[0][v].mx);
}

int main()
{
    ll tc; scanf("%lld", &tc);
    ll k = 0;
    while (tc--){
     scanf("%lld", &n);
    for (int i = 0; i < n-1; i ++){
        ll u, v, w; scanf("%lld %lld %lld", &u, &v, &w);
        u --, v --;
        v1[u].push_back({v, w});
        v1[v].push_back({u, w});
    }

    memset(tbl, -1, sizeof tbl);
    memset(dep, -1, sizeof dep);
    for (int i = 0; i <= lg; i ++){
        for (int j = 0; j < n; j ++){
            a1[i][j].mn = inf;
            a1[i][j].mx = -inf;
        }
    }

    dfs(0, -1, 0, 0);
    sprs_tbl();
    scanf("%lld", &q);
    printf("Case %lld:\n", ++k);
    while (q--){
        ll u, v; scanf("%lld %lld", &u, &v);
        u --, v --;
        mn1 = inf, mx1 = -inf;
        _lca(u, v);
        printf("%lld %lld\n",mn1, mx1);
    }

    for (int i = 0; i < n; i ++){
        v1[i].clear();
    }

    }

    return 0;
}
