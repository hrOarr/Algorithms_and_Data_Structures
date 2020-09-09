#include "bits/stdc++.h";
using namespace std;
typedef long long int ll;
const int N=1e5+5,inf=1e9+7;
void _counting(int A[],int n)
{
    int mn=*min_element(A,A+n);
    int mx=*max_element(A,A+n);
    int d=mx-mn+1;
    int cnt[d+1],out[n+1];
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++){
        cnt[A[i]-mn]++;
    }
    for(int i=1;i<=d;i++){
        cnt[i]+=cnt[i-1];
    }
    for(int i=0;i<n;i++){
        out[cnt[A[i]-mn]-1]=A[i];
        cnt[A[i]-mn]--;
    }
    for(int i=0;i<n;i++){
        A[i]=out[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;int A[n+1];
    for(int i=0;i<n;i++)cin>>A[i];
    _counting(A,n);
    printf("Sorted list: ");
    for(int i=0;i<n;i++)cout<<" "<<A[i];
    cout<<"\n";

    return 0;
}
