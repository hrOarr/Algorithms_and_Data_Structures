#include "bits/stdc++.h";
using namespace std;
typedef long long int ll;
const int N=1e5+5,inf=1e9+7;
void _selection(int A[],int n)
{
    for(int i=0;i<n-1;i++){
        int mn_id=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[mn_id]){
                mn_id=j;
            }
        }
        swap(A[i],A[mn_id]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;int A[n+1];
    for(int i=0;i<n;i++)cin>>A[i];
    _selection(A,n);
    printf("Sorted list: ");
    for(int i=0;i<n;i++)cout<<" "<<A[i];
    cout<<"\n";

    return 0;
}
