void tarzan(int u)
{
   low[u] = disc[u] = ++tim;
   vis[u] = true;
   st.push(u);
   vector<int> ::iterator it;
   for(it = vv[u].begin(); it != vv[u].end(); it++){
        int v = (*it);
        if (disc[v] == -1){
            tarzan(v);
            low[u] = min(low[u],low[v]);
        }
        else if (vis[v]) low[u] = min(low[u],disc[v]);
   }
   if (low[u] == disc[u]){
      scc[++id] = u;
      while (st.top() != u){
          int v = st.top();
          vis[v] = false;
          st.pop();
      }
      int v = st.top();
      vis[v] = false;
      st.pop();
   }
}
