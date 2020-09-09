#include "bits/stdc++.h";
using namespace std;
typedef long long int ll;
const int N=1e5+5,inf=1e9+7;
void swap(int* a, int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int _partition(int A[], int lo, int hi)
{
    int pivot = A[hi];
    int i=lo-1;
    for(int j=lo;j<=hi-1;j++){
        if(A[j]<pivot){
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[hi]);
    return i+1;
}
void _quick(int A[], int lo, int hi)
{
    if(lo<hi){
        int pivot=_partition(A,lo,hi);
        _quick(A,lo,pivot-1);
        _quick(A,pivot+1,hi);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;int A[n+1];
    for(int i=0;i<n;i++)cin>>A[i];
    _quick(A,0,n-1);
    printf("Sorted list: ");
    for(int i=0;i<n;i++)cout<<" "<<A[i];
    cout<<"\n";

    return 0;
}

