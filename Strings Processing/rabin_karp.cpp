#include "bits/stdc++.h";
using namespace std;
typedef long long int ll;
const int N=1e5+5,inf=1e9+7;
#define d 256
void rabin_karp(string txt,string pat, int p)
{
    int n=txt.size(),m=pat.size();
    int i,j,q=0,t=0,h=1;
    for(int i=0;i<m-1;i++){
        h=(h*d)%p;
    }
    for(int i=0;i<m;i++){
        q=(q*d+pat[i])%p;
        t=(t*d+txt[i])%p;
    }
    for(i=0;i<=n-m;i++){
        if(q==t){
            for(j=0;j<m;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==m){
                cout<<"Found at index "<<i<<"\n";
            }
        }
        if(i<n-m){
            t=(d*(t-txt[i]*h)+txt[i+m])%p;
            t=(t+p)%p;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    string s,pat;cin>>s>>pat;
    rabin_karp(s,pat,101);

    return 0;
}

