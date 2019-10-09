#include "bits/stdc++.h"
using namespace std;

#define  L  2*nod
#define  R  2*nod+1LL
typedef long long int ll;
const ll N   = 1000010;
const ll mod = 1e9+7LL;

ll T[4*N+2LL];

ll mid(ll x,ll y){return (x+y)/2;}

void updt( ll nod,ll lo,ll hi,ll l,ll r,ll v )
{
    if ( lo > r || hi < l ) return;
    if ( lo >= l && hi <= r ){
        T[nod] = (T[nod]%mod+v)%mod;
        return;
    }
    ll m = mid(lo,hi);
    updt(L,lo,m,l,r,v);
    updt(R,m+1LL,hi,l,r,v);

    T[nod] = (T[L]%mod+T[R]%mod)%mod;
}

ll qry(ll nod,ll lo,ll hi,ll l,ll r)
{
    if (lo > r || hi < l) return 0;
    if (lo >= l && hi <= r) return T[nod];
    ll m = mid(lo,hi);
    ll r1 = qry(L,lo,m,l,r);
    ll r2 = qry(R,m+1LL,hi,l,r);
    return (r1%mod+r2%mod)%mod;
}

int main()
{
    //cout << mod << "\n";
    ll tc; cin >> tc;
    ll k = 0;
    while (tc--){
    ll n; cin >> n;
    ll a1[n+2]; set <ll> st;
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &a1[i]);
        st.insert(a1[i]);
    }
    set <ll> ::iterator it;
    vector <ll> vv;
    for(it = st.begin(); it != st.end(); it++) vv.push_back((*it));
    sort(vv.begin(),vv.end());
    ll sz = st.size();
    for(int i = 1; i <= n; i ++){
        ll p = lower_bound(vv.begin(),vv.end(),a1[i] )-vv.begin();
        if (!p) updt(1,1,sz,1,1,1);
        else {
            ll q = qry(1,1,sz,1,p);
           // cout << q << "*\n";
            updt(1,1,sz,p+1,p+1,q+1);
        }
       // cout << p << "**\n";
    }
    cout << "Case " << ++k << ": ";
    cout << T[1] << "\n";
    vv.clear();
    st.clear();
    for(int i = 0; i <= 4*n+2; i ++) T[i] = 0;
    }


    return 0;
}
