#include "bits/stdc++.h";
using namespace std;
typedef long long int ll;
const int N=1e5+5,inf=1e9+7;
void _heapify(int A[],int n,int mx) // max-heap
{
    int lft=2*mx+1,rgt=2*mx+2,tmp=mx;
    if(lft<n&&A[lft]>A[mx]){
        mx=lft;
    }
    if(rgt<n&&A[rgt]>A[mx]){
        mx=rgt;
    }
    if(tmp!=mx){
        swap(A[tmp],A[mx]);
        _heapify(A,n,mx);
    }
}
void _heap(int A[],int n)
{
    for(int i=n/2-1;i>=0;i--){
        _heapify(A,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(A[0],A[i]);
        _heapify(A,i,0);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;int A[n+1];
    for(int i=0;i<n;i++)cin>>A[i];
    _heap(A,n);
    printf("Sorted list: ");
    for(int i=0;i<n;i++)cout<<" "<<A[i];
    cout<<"\n";

    return 0;
}
