#include"bits/stdc++.h"
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
typedef long long int ll;
const ll N=1e5+2,inf=1e14+7;
void _run();
void no(){cout<<"-1\n",exit(0);}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	_run();
	return 0;
}
bitset<N>bs[27],on,rs;
void _run()
{
    string s;cin>>s;
    for(int i=0;i<(int)s.size();i++)
        bs[s[i]-'a'][i]=1;
    for(int i=0;i<N;i++)on[i]=1;
    int q;cin>>q;
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int id;cin>>id;
            string p;cin>>p;
            bs[s[id-1]-'a'][id-1]=0;
            s[id-1]=p[0];
            bs[s[id-1]-'a'][id-1]=1;
        }
        else
        {
            int l,r;cin>>l>>r;--l;
            int d=r-l;
            string pat;cin>>pat;
            if((int)pat.size()>d)
            {
                cout<<"0\n";
                continue;
            }
            rs=on>>(N-(d-(int)pat.size()+1));
            for(int i=0;i<(int)pat.size();i++)
                rs &= bs[pat[i]-'a']>>(l+i);
            cout<<(int)rs.count()<<"\n";
        }
    }
}
