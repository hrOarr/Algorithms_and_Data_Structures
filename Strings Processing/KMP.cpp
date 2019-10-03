#include"bits/stdc++.h"
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
typedef long long int ll;
const ll N=1e6+2,inf=1e14+7;
void _run();
void no(){cout<<"-1\n",exit(0);}
int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);
	_run();
	return 0;
}
int f[N];
vector<int>vec;
void KMP( string txt,string pat )
{
    // failure function
   for(int i=1;i<pat.size();i++)
   {
       int j=f[i-1];
       while(j>0&&pat[i]!=pat[j])j=f[j-1];
       if(pat[i]==pat[j])j++;
       f[i]=j;
   }

   // find substring
   int i=0,j=0;
   vector<int>occur;
   while(i<txt.size())
   {
       if(txt[i]==pat[j])i++,j++;
       if(j==pat.size())
       {
           occur.pb(i-j);
           j=f[j-1];
       }
       if(i<txt.size()&&txt[i]!=pat[j])
       {
           if(j!=0)j=f[j-1];
           else i++;
       }
   }
   cout<<occur.size()<<"\n";
   for(auto x:occur)cout<<x<<" ";
   cout<<"\n";
}
void _run()
{
    string s1,s2;cin>>s1>>s2;
    KMP(s1,s2);
}
