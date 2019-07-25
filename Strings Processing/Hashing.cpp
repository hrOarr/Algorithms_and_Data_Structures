#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
const int N = 1e9+7;
unordered_map<ll,bool>vis,vis2;
ll Bigmod( ll b,ll p,ll m )
{
    ll rt = 1;
    while(p)
    {
        if(p&1)rt=(rt*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return rt;
}
int main()
{
    int n;cin>>n;
    while(n--)
    {
        string s;cin>>s;
        ll now = 0;
        for(int i=0;i<s.size();i++)
            now = (now + ((s[i]-'a'+1)*Bigmod(31LL,i,N))%N )%N;
        vis[now] = 1;
        now = 0;
        for(int i=s.size()-1;i>=0;i--)
            now = (now + ((s[i]-'a'+1)*Bigmod(31LL,s.size()-i-1,N))%N )%N;
        vis2[now] = 1;
    }
    int q;cin>>q;
    while(q--)
    {
        string s;cin>>s;
        ll now = 0,now2 = 0;
        for(int i=0;i<s.size();i++)
            now = (now + ((s[i]-'a'+1)*Bigmod(31LL,i,N))%N )%N;
        for(int i=s.size()-1;i>=0;i--)
            now2 = (now2 + ((s[i]-'a'+1)*Bigmod(31LL,s.size()-i-1,N))%N )%N;
        if( vis[now]&&vis2[now2] )cout<< "yes\n";
        else cout<< "no\n";
    }

    return 0;
}
