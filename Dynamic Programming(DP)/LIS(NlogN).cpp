void _lis()
{
    multiset<int>st;
    for(int i=1;i<=n;i++)
    {
        st.insert(A[i]);
        auto it=upper_bound(A[i]);
        if(it!=st.end())st.erase(A[i]);
    }
    cout<<st.size()<<"\n";
}