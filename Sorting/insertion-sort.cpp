#include "bits/stdc++.h";
using namespace std;
typedef long long int ll;
const int N=1e5+5,inf=1e9+7;
void _insertion(int A[],int n)
{
    for(int i=0;i<n;i++){
        int j=i-1,key=A[i];
        while(j>=0&&A[j]>key){
            A[j+1]=A[j--];
        }
        A[j+1]=key;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;int A[n+1];
    for(int i=0;i<n;i++)cin>>A[i];
    _insertion(A,n);
    printf("Sorted list: ");
    for(int i=0;i<n;i++)cout<<" "<<A[i];
    cout<<"\n";

    return 0;
}
