#include "bits/stdc++.h";
using namespace std;
typedef long long int ll;
const int N=1e5+5,inf=1e9+7;
void _counting(int A[],int n,int exp)
{
    int cnt[11],out[n+1];
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++){
        cnt[(A[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        cnt[i]+=cnt[i-1];
    }
    for(int i=0;i<n;i++){
        out[cnt[(A[i]/exp)%10]-1]=A[i];
        cnt[(A[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        A[i]=out[i];
    }
}
void _radix(int A[],int n)
{
    int mx=*max_element(A,A+n);
    for(int exp=1;mx/exp>0;exp*=10){
        _counting(A,n,exp);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;int A[n+1];
    for(int i=0;i<n;i++)cin>>A[i];
    _radix(A,n);
    printf("Sorted list: ");
    for(int i=0;i<n;i++)cout<<" "<<A[i];
    cout<<"\n";

    return 0;
}
