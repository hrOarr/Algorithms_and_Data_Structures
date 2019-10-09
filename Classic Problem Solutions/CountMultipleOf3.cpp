#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
const ll N = 100010;

struct lol
{
    ll one,two,zero,lz;
};

lol tree[3*N+2];

void _rev(ll node)
{
    ll tmp1 = tree[node].one;
    ll tmp2 = tree[node].two;
    tree[node].one = tree[node].zero;
    tree[node].two = tmp1;
    tree[node].zero = tmp2;
}

void _add(ll node)
{
    tree[node].zero = tree[2 * node].zero + tree[2 * node + 1].zero;
    tree[node].one = tree[2 * node].one + tree[2 * node + 1].one;
    tree[node].two = tree[2 * node].two + tree[2 * node + 1].two;
}

void build(ll node, ll lo, ll hi)
{
    if (lo == hi){
        tree[node].zero = 1;
        return;
    }
    ll mid = (lo + hi) / 2;
    build(2 * node, lo, mid);
    build(2 * node + 1, mid + 1, hi);
    _add(node);
}

void updt(ll node, ll lo, ll hi, ll l, ll r)
{
    if (l > hi || r < lo) return;
    if (lo >= l && hi <= r){
        _rev(node);
        tree[node].lz ++;
        return;
    }
    if (tree[node].lz){
        tree[2 * node].lz += tree[node].lz;
        tree[2 * node + 1].lz += tree[node].lz;
        tree[node].lz %= 3;
        for (int i = 0; i < tree[node].lz; i ++){
            _rev(2 * node);
            _rev(2 * node + 1);
        }
        tree[node].lz = 0;
    }
    ll mid = (lo + hi) / 2;
    updt(2 * node, lo, mid, l, r);
    updt(2 * node + 1, mid + 1, hi, l, r);
    _add(node);
}

ll qry(ll node, ll lo, ll hi, ll l, ll r)
{
    if (l > hi || r < lo) return 0;
    if (lo >= l && hi <= r) return tree[node].zero;
    if (tree[node].lz){
        tree[2 * node].lz += tree[node].lz;
        tree[2 * node + 1].lz += tree[node].lz;
        tree[node].lz %= 3;
        for (int i = 0; i < tree[node].lz; i ++){
            _rev(2 * node);
            _rev(2 * node + 1);
        }
        tree[node].lz = 0;
    }

    ll mid = (lo + hi) / 2;
    ll p1 = qry(2 * node, lo, mid, l, r);
    ll p2 = qry(2 * node + 1, mid + 1, hi, l, r);

    return (p1 + p2);
}

int main()
{
    ll tc; scanf("%lld", &tc);
    ll k = 0;
    while (tc--){
        ll n, q; scanf("%lld %lld", &n, &q);
        build(1, 1, n);
        printf("Case %lld:\n", ++k);
        while (q--){
            ll f, l, r; scanf("%lld%lld%lld", &f, &l, &r);
            if (f) printf("%lld\n", qry(1, 1, n, l+1, r+1));
            else updt(1, 1, n, l+1, r+1);
        }
        for (int i = 0; i < 3 * n + 1; i ++){
            tree[i].lz = 0;
            tree[i].zero = 0;
            tree[i].one = 0;
            tree[i].two = 0;
        }
    }


    return 0;
}
