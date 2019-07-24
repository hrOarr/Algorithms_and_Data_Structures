vector<int>vec[N];
stack<pair<int,int> >st;
int disc[N],low[N],cnt,pr[N],tm;
void dfs(int u)
{
    disc[u]=low[u]=++tm;
    int sz=0;
    for(auto v:vec[u])
    {
        if(disc[v]==-1)
        {
            ++sz;pr[v]=u;
            st.push(mp(u,v));
            dfs(v);
            low[u]=min(low[u],low[v]);
            if((pr[u]==-1&&sz>1)||(pr[u]!=-1&&low[v]>=disc[u]))
            {
                while(st.top().fs!=u||st.top().sc!=v)
                {
                    cout<<st.top().fs<<"->"<<st.top().sc<<" ";
                    st.pop();
                }
                cout<<st.top().fs<<"->"<<st.top().sc<<" ";
                st.pop();cout<<"\n";
                ++cnt;
            }
        }
        else if(v!=pr[u]&&disc[v]<low[u])
        {
            low[u]=min(low[u],disc[v]);
            st.push(mp(u,v));
        }
    }
}
