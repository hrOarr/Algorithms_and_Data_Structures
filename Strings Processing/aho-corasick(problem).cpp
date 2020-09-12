// minimum length of such a string t
// that t is a substring of s and
// mi has at least ki occurrences as a substring in t
#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
const int N = 1e5+5,inf = 1e9+7;
vector<int>res[N];
string s,tmp;
int T[26*N][26],End[26*N],fail[N],nod=1;
int lastEnd[26*N],len[N],lim[N],n;
void insrt( int id )
{
    int cur = 1;
    for(int i=0;i<tmp.size();i++)
    {
        int a = tmp[i]-'a';
        if( T[cur][a] )cur = T[cur][a];
        else cur = T[cur][a] = ++nod;
    }
    End[cur] = id;
}
void make_fail()
{
    for(int i=0;i<26;i++)
        T[0][i] = 1;
    queue<int>q1;
    q1.push(1);
    fail[1] = 0;
    while(!q1.empty())
    {
        int cur = q1.front();
        q1.pop();
        for(int i=0;i<26;i++)
        {
            if(!T[cur][i])continue;
            int nw = fail[cur];
            while(!T[nw][i])nw = fail[nw];
            fail[T[cur][i]] = T[nw][i];
            q1.push(T[cur][i]);
        }
    }
}
int lol( int cur )
{
    if(cur<=1)return 0;
    if(lastEnd[cur]==-1)lastEnd[cur] = lol(fail[cur]);
    return End[cur]?cur:lastEnd[cur];
}
void qry()
{
    int cur = 1;
    for(int i=0;i<s.size();i++)
    {
        int a = s[i]-'a';
        while(!T[cur][a])cur = fail[cur];
        cur = T[cur][a];
        for(int j=cur;j;j=lastEnd[j])
        {
            if( End[j] )
                res[End[j]].push_back(i);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>s>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>lim[i]>>tmp;
        len[i] = tmp.size();
        insrt(i);
    }
    make_fail();
    memset(lastEnd,-1,sizeof lastEnd);
    for(int i=2;i<=nod;i++)lol(i);
//    for(int i=1;i<=nod;i++)
//    {
//        cout<<i<< ": "<<lastEnd[i]<< "\n";
//    }
//    for(int i=1;i<=nod;i++)
//    {
//        cout<<i<< ": "<<fail[i]<< "\n";
//    }
    qry();
    for(int i=1;i<=n;i++)
    {
        if( res[i].size()<lim[i] )
            cout<< "-1\n";
        else
        {
            int ans = inf;
            for(int j=0;j+lim[i]-1<res[i].size();j++)
                ans = min(ans,res[i][j+lim[i]-1]-res[i][j]);
            cout<<ans+len[i]<< "\n";
        }
    }

}
