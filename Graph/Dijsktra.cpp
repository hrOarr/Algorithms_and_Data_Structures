void dijkstra(int s)
{
        for(int i=1;i<=n;i++)dis[i]=inf;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push(mp(0,s)); // mp=make_pair
	dis[s]=0;
	while(!pq.empty())
        {
		auto rt=pq.top();pq.pop();
		int d=rt.fs,u=rt.sc;
		if(d>dis[u])continue;
		for(auto x:vec[u])
		{
			if(dis[u]+x.sc<dis[x.fs])
			{
				dis[x.fs]=dis[u]+x.sc;
				pr[x.fs]=u;
				pq.push(make_pair(dis[x.fs],x.fs));
			}
		}
	}
}
void _printPath(int u)
{
    if(pr[u]==-1)return;
    _printPath(pr[u]);
	cout<<u<<" ";
}
