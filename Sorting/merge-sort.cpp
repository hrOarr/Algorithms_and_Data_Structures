#include "bits/stdc++.h";
using namespace std;
typedef long long int ll;
const int N=1e5+5,inf=1e9+7;
void _merge(int A[],int lo,int md,int hi)
{
    int n1=md-lo+1,n2=hi-md;
    int lft[n1+1],rgt[n2+1];
    for(int i=0;i<n1;i++){
        lft[i]=A[i+lo];
    }
    for(int i=0;i<n2;i++){
        rgt[i]=A[md+i+1];
    }
    int i=0,j=0,k=lo;
    while(i<n1&&j<n2){
        if(lft[i]<=rgt[j]){
            A[k++]=lft[i++];
        }
        else{
            A[k++]=rgt[j++];
        }
    }
    while(i<n1){
        A[k++]=lft[i++];
    }
    while(j<n2){
        A[k++]=rgt[j++];
    }
}
void _mergesort(int A[],int lo,int hi)
{
    if(lo<hi){
        int md=(lo+hi)>>1;
        _mergesort(A,lo,md);
        _mergesort(A,md+1,hi);

        _merge(A,lo,md,hi);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;int A[n+1];
    for(int i=0;i<n;i++)cin>>A[i];
    _mergesort(A,0,n-1);
    printf("Sorted list: ");
    for(int i=0;i<n;i++)cout<<" "<<A[i];
    cout<<"\n";

    return 0;
}
