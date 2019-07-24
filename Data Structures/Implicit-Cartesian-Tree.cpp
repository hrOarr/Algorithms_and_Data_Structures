#include "bits/stdc++.h"
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    rope<int>vec;
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
        vec.push_back(i);
    int l,r;
    while(q--)
    {
        cin>>l>>r;
        --l,--r;
        rope<int>cur = vec.substr(l,r-l+1);
        vec.erase(l,r-l+1);
        vec.insert(vec.mutable_begin(),cur);
    }
    for(auto x:vec)
        cout<<x<< " ";


}