#define  F  first
#define  S  second
#define  pb push_back
#define  mp make_pair
#define  sz(s) (int)s.size()
typedef long long int ll;
#define  PII pair<ll,ll>
const int N = 1e5+5;
vector<PII>pt1,pt2,H1,H2;
multiset<PII>st1,st2;
ll pw( ll x )
{
    return(x*x);
}
ll Dis( PII A,PII B )
{
    return pw(A.F-B.F)+pw(A.S-B.S);
}
ll Cross( PII A,PII B,PII C )
{
    return (B.F-A.F)*(C.S-A.S)-(B.S-A.S)*(C.F-A.F);
}
void Convex( vector<PII>pt,vector<PII>&Hull )
{
    Hull.clear();
    sort(pt.begin(),pt.end());
    for(int i=0;i<sz(pt);i++)
    {
        while( sz(Hull)>=2&&Cross(Hull[sz(Hull)-2],Hull.back(),pt[i])<=0 )
            Hull.pop_back();
        Hull.pb(pt[i]);
    }
    int siz = sz(Hull);
    for(int i=sz(pt)-2;i>=0;i--)
    {
        while( sz(Hull)>=siz+1 && Cross(Hull[sz(Hull)-2],Hull.back(),pt[i])<=0 )
            Hull.pop_back();
        Hull.pb(pt[i]);
    }
    Hull.pop_back();
   // Hull.pb(pt[0]);
}
