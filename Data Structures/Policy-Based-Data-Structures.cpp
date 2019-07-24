#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
typedef long long int ll;
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<ll, int> , null_type, less<pair<ll, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll N = 1e6+6,mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /// keep in mind about data type

//    cout<<*X.find_by_order(1)<< "\n";
//    cout<<*X.find_by_order(2)<< "\n";
//    cout<<*X.find_by_order(4)<< "\n";

    ordered_set S;
    S.insert(make_pair(0,0));
    ll n,k;cin>>n>>k;
    ll sum = 0,Res = 0;
    for(int i=0;i<n;i++)
    {
        ll x;cin>>x;
        sum += x;
        Res += (i+1)-S.order_of_key(make_pair(sum-k,1e9+7));
        S.insert(make_pair(sum,i+1));
    }
    cout<<Res<< "\n";


    return 0;
}