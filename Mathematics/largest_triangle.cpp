#include"bits/stdc++.h"
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
typedef long long int ll;
const ll N=1e6+2,inf=1e9+7;
void _run();
void no(){cout<<"-1\n",exit(0);}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	_run();
	return 0;
}
ll _pw(ll x){return x*x;}
ll _dis(pair<ll,ll>A,pair<ll,ll>B){return _pw(A.fs-B.fs)+_pw(A.sc-B.sc);}
ll _cross(pair<ll,ll>A,pair<ll,ll>B,pair<ll,ll>C)
{
    return (B.fs-A.fs)*(C.sc-A.sc)-(B.sc-A.sc)*(C.fs-A.fs);
}
void _convex(vector<pair<ll,ll> >pnt,vector<pair<ll,ll> >&H)
{
    H.clear();
    sort(pnt.begin(),pnt.end());
    for(auto x:pnt)
    {
        while(H.size()>=2&&_cross(H[H.size()-2],H.back(),x)<=0)H.pop_back();
        H.pb(x);
    }
    int sz=H.size();
    for(int i=pnt.size()-2;i>=0;i--)
    {
        while(H.size()>=sz+1&&_cross(H[H.size()-2],H.back(),pnt[i])<=0)H.pop_back();
        H.pb(pnt[i]);
    }
    H.pop_back();
}
ll _area(vector<pair<ll,ll> >&H,int lo,int md,int hi)
{
    int n=H.size();
    lo=(lo+n)%n;
    md=(md+n)%n;
    hi=(hi+n)%n;
    ll rt=0;
    rt+=H[lo].fs*H[md].sc;
    rt+=H[md].fs*H[hi].sc;
    rt+=H[hi].fs*H[lo].sc;

    rt-=H[md].fs*H[lo].sc;
    rt-=H[hi].fs*H[md].sc;
    rt-=H[lo].fs*H[hi].sc;
    return abs(rt);
}
void _run()
{
    int n;cin>>n;
    vector<pair<ll,ll> >pnt;
    for(int i=0;i<n;i++)
    {
        int x,y;cin>>x>>y;
        pnt.pb(mp(x,y));
    }
    vector<pair<ll,ll> >H;
    _convex(pnt,H);
    ll rs=0;
    n=H.size();
    for(int i=0;i<n;i++)
    {
        int m=i+1;
        for(int j=0;j<n-2;j++)
        {
            int k=i+j+2;
            ll cur=_area(H,i,m,k);
            while(true)
            {
                m++;
                ll tm=_area(H,i,m,k);
                if(tm<=cur||m>=k)break;
                cur=tm;
            }
            m=max(i+1,m-2);
            rs=max(rs,cur);
        }
    }
    cout<<fixed<<setprecision(10)<<rs/2.0<<"\n";
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      