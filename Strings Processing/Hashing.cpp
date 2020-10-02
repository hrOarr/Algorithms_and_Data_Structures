#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
const ll N=1e5+5,inf=1e9+7,mod=998244353;
int vs[N];
ll bigmod(ll b,ll p,ll m)
{
    ll rt=1;
    while(p){
        if(p&1){
            rt=(rt*b)%m;
        }
        b=(b*b)%m;
        p>>=1;
    }
    return rt;
}
ll _hash(string s,ll md)
{
    ll rt=0;
    for(int i=0;i<s.size();i++){
        rt=(rt*31LL+(s[i]-'a'+1))%md;
    }
    return rt;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;ll pw[2*n*k+2],pw2[2*n*k+1];
    pw[0]=pw2[0]=1;ll Hash[2*n*k+2],Hash2[2*n*k+2];Hash[0]=Hash2[0]=0;
    for(int i=1;i<=2*n*k;i++){
        pw[i]=(pw[i-1]*31LL)%inf;
        pw2[i]=(pw2[i-1]*31LL)%mod;
    }
    string s;cin>>s;
    s=s+s;s='#'+s;
    for(int i=1;i<=2*n*k;i++){
        Hash[i]=(Hash[i-1]*31LL+(s[i]-'a'+1))%inf;
        Hash2[i]=(Hash2[i-1]*31LL+(s[i]-'a'+1))%mod;
    }
    int g;cin>>g;map<pair<ll,ll>,ll>hashes;
    for(int i=1;i<=g;i++){
        string x;cin>>x;
        hashes[make_pair(_hash(x,inf),_hash(x,mod))]=i;
    }
    int rs[n+1];
    for(int i=1;i<=k;i++){
        bool f=1;int id=0;
        for(int j=i;j<i+n*k;j+=k){
            ll cur=(Hash[j+k-1]-(Hash[j-1]*pw[k])%inf+inf)%inf;
            ll cur2=(Hash2[j+k-1]-(Hash2[j-1]*pw2[k])%mod+mod)%mod;
            if(hashes.count(make_pair(cur,cur2))==0){
                f=0;break;
            }
            int idx=hashes[make_pair(cur,cur2)];
            if(vs[idx]){
                f=0;break;
            }
            rs[++id]=idx;
            vs[idx]++;
            //cout<<id<<"*\n";
            if(id==n)break;
        }
        if(f){
            cout<<"YES\n";
            for(int i=1;i<=n;i++){
                cout<<rs[i]<<" ";
            }
            cout<<"\n";
            exit(0);
        }
        else{
            memset(vs,0,sizeof vs);
        }
    }
    cout<<"NO\n";



    return 0;
}

////
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


////

#include"bits/stdc++.h"
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
typedef long long int ll;
const ll N=1e6+2,inf=1e9+7;
void _run();
void no(){cout<<"Impossible\n",exit(0);}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	_run();
	return 0;
}
ll Mod[4],pw[N][4],base[4],Hash[N][4];
string s;int n;
void _hashProcess()
{
    for(int i=0;i<4;i++)
    {
        Mod[i]=rand()%inf +inf;
        Hash[0][i]=0;
        pw[0][i]=1;
        base[i]=10;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        {
            Hash[i][j]=(Hash[i-1][j]*base[j]+(s[i-1]-'0'))%Mod[j];
            pw[i][j]=(pw[i-1][j]*10LL)%Mod[j];
        }
    }
}
ll _getHash(int l,int r,int id)
{
    return (Hash[r][id]-(Hash[l-1][id]*pw[r-l+1][id])%Mod[id]+Mod[id])%Mod[id];
}
void _result(int pls,int eql)
{
    for(int i=0;i<4;i++)
    {
        if((_getHash(1,pls,i)+_getHash(pls+1,eql,i))%Mod[i]!=_getHash(eql+1,n,i))
            return;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<(char)s[i-1];
        if(i==pls)cout<<"+";
        else if(i==eql)cout<<"=";
    }
    cout<<"\n";exit(0);
}
void _run()
{
    cin>>s;n=(int)s.size();
    _hashProcess();
    for(int i=1;i<n;i++)
    {
        if((n-i)/2 >1&&s[i]!='0')_result(i,i+(n-i)/2);
        else if((n-i)/2==1)_result(i,i+(n-i)/2);
        _result(i,n-i);
        _result(i,n-i-1);
    }
}
