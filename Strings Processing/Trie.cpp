#include<bits/stdc++.h>
using namespace std;
const int N=500500;
int nod,cnt[N],T[N][27];
bool vs[N];
void _insert(string s)
{
    int cur=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=s[i]-'a';
        if(!vs[T[cur][c]])
        {
            T[cur][c]=++nod;
            vs[nod]=1;
        }
        cur=T[cur][c];
    }
    ++cnt[cur];
}
bool qry(string s)
{
    int cur=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=s[i]-'a';
        if(!vs[T[cur][c]])return false;
        cur=T[cur][c];
    }
    return cnt[cur]>0;
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        string s;cin>>s;
        _insert(s);
    }
    for(int i=0; i<m; i++)
    {
        string s;cin>>s;
        if(qry(s))cout<<"YES\n";
        else cout<<"NO\n";
    }
}
