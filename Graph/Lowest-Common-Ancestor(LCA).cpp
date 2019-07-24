void dfs(int u,int p)
{
	tbl[u][0]=p;
	for(int i=1;i<=logn;i++)
		tbl[u][i]=tbl[tbl[u][i-1]][i-1];
	for(auto v:vec[u])
        {
             if(v==p)continue;
             dep[v]=dep[u]+1;
             dfs(v,u);
	}
}

int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=logn;i>=0;i--)
		if(dep[u]-(1 << i)>=dep[v])
			u=tbl[u][i];
	if(u==v)return u;
	for(int i=logn;i>=0;i--)
        {
		if(tbl[u][i]!=-1&&tbl[u][i]!=tbl[v][i])
		{
			u=tbl[u][i];
			v=tbl[v][i];
		}
	}
	return tbl[u][0];
}
