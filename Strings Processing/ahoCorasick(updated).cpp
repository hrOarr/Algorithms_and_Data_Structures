#include "bits/stdc++.h"
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
typedef long long int ll;
const ll N = 2e6+6,inf = 1e9+7;
vector<int>vec[N];
int nod,sffx_link[N],T[N][82],End[N],frq[N];
string s;
void insrt(int id)
{
    int sz = s.size(),cur = 0;
    for(int i=0;i<sz;i++)
    {
        int ch = s[i]-'-'+1;
        if(T[cur][ch]==-1)
            T[cur][ch] = ++nod;
        cur = T[cur][ch];
    }
    End[id] = cur;
}
void suffix_automaton()
{
    queue<int>Q;
    for(int i=0;i<81;i++)
    {
        if(T[0][i]==-1)continue;
        Q.push(T[0][i]);
        vec[0].pb(T[0][i]);
    }
    while(Q.size())
    {
        int cur = Q.front();
        Q.pop();
        for(int i=0;i<81;i++)
        {
            int nxt = T[cur][i];
            if(nxt==-1)continue;
            int x = sffx_link[cur];
            while(x&&T[x][i]==-1)x = sffx_link[x];
            if(T[x][i]!=-1)
                sffx_link[nxt] = T[x][i];
            vec[sffx_link[nxt]].pb(nxt);
            Q.push(nxt);
        }
    }
}
int next_state(int cur,int ch)
{
    while(cur&&T[cur][ch]==-1)cur = sffx_link[cur];
    if(T[cur][ch]!=-1)
        cur = T[cur][ch];
    return cur;
}
void dfs(int cur)
{
    for(auto nxt:vec[cur])
    {
        if(cur==nxt)continue;
        dfs(nxt);
        frq[cur] += frq[nxt];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(T,-1,sizeof T);
    int k;cin>>k;
    for(int i=1;i<=k;i++)
        cin>>s,insrt(i);
    suffix_automaton();
    int q;cin>>q;
    while(q--)
    {
        cin>>s;
        int sz = s.size(),cur = 0;
        for(int i=0;i<sz;i++)
        {
            cur = next_state(cur,s[i]-'-'+1);
            frq[cur]++;
        }
    }
    //cout<< "**\n";
    dfs(0);
    for(int i=1;i<=k;i++)
        cout<<frq[End[i]]<< "\n";


}

