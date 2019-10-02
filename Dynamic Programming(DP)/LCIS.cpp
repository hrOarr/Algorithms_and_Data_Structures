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
	ios_base::sync_with_stdio(0);cin.tie(0);
	_run();
	return 0;
}
int n,m,A[N],B[N],prv[502],lis[N];
void _print(int x)
{
    if(x==-1)return;
    _print(prv[x]);
    cout<<B[x]<<" ";
}
void _lis()
{
    memset(prv,-1,sizeof prv);
    for(int i=1;i<=n;i++)
    {
        int cnt=0,lst=-1;
        for(int j=1;j<=m;j++)
        {
            if(A[i]==B[j]&&lis[j]<cnt+1)
                lis[j]=cnt+1,prv[j]=lst;
            else if(A[i]>B[j]&&lis[j]>cnt)
                cnt=lis[j],lst=j;
        }
    }
    int st=-1,rs=0;
    for(int i=1;i<=m;i++)
    {
        if(rs<lis[i])rs=lis[i],st=i;
    }
    cout<<rs<<"\n";
    _print(st);
    cout<<"\n";
}
void _run()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>A[i];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>B[i];
    _lis();
}
