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
vector<int>vec[N];
int n,rs[N],dep[N],curmx[(1<<22)+2],cumxr[N],siz[N];
string ch[N];
void dfs0(int u,int pr)
{
    if(pr!=-1)cumxr[u]=cumxr[pr]^(1<<(int)(ch[u][0]-'a')),dep[u]=dep[pr]+1;
    siz[u]=1;
    for(auto v:vec[u])
    {
        dfs0(v,u);
        siz[u]+=siz[v];
    }
}
void _add(int u,int pr,int x)
{
    if(x==1)curmx[cumxr[u]]=max(curmx[cumxr[u]],dep[u]);
    else curmx[cumxr[u]]=-inf;
    for(auto v:vec[u])
    {
        if(v==pr)continue;
        _add(v,u,x);
    }
}
int _cal(int u,int pr)
{
    int rt=dep[u]+curmx[cumxr[u]];
    for(int i=0;i<22;i++)rt=max(rt,dep[u]+curmx[cumxr[u]^(1<<i)]);
    for(auto v:vec[u])
    {
        if(v==pr)continue;
        rt=max(rt,_cal(v,u));
    }
    return rt;
}
void dfs(int u,int pr,bool f)
{
    int mx=-1,id=-1;
    for(auto v:vec[u])
    {
        if(v==pr)continue;
        if(siz[v]>mx)mx=siz[v],id=v;
    }
    for(auto v:vec[u])
    {
        if(v==pr||v==id)continue;
        dfs(v,u,1);
    }
    if(id!=-1)dfs(id,u,0);
    for(auto v:vec[u])
    {
        if(v==pr||v==id)continue;
        rs[u]=max(rs[u],_cal(v,u));
        _add(v,u,1);
    }
    int cur=dep[u]+curmx[cumxr[u]];
    for(int i=0;i<22;i++)cur=max(cur,dep[u]+curmx[cumxr[u]^(1<<i)]);
    rs[u]=max(rs[u],cur);
    rs[u]-=2*dep[u];
    for(auto v:vec[u])rs[u]=max(rs[u],rs[v]);
    curmx[cumxr[u]]=max(curmx[cumxr[u]],dep[u]);
    if(f)_add(u,pr,-1);
}
void _run()
{
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x>>ch[i]; // character in edges
        vec[x].pb(i);
    }
    dfs0(1,-1);
    for(int i=0;i<(1<<22)+2;i++)curmx[i]=-inf;
    dfs(1,-1,0);
    for(int i=1;i<=n;i++)
    {
        if(rs[i]<0)rs[i]=0;
        cout<<rs[i]<<" ";
    }
    cout<<"\n";
}
