bool BellmanFord(int s,int n)
{
	dis[s]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int u=0;u<n;u++)
                {
			for(auto x:vec[u])
				dis[x.fs]=min(dis[x.fs],dis[u]+x.sc);
		}
	}
	bool f=0;
	for(int u=0;u<n;u++)
        {
		for(auto x:vec[u])
			if(dis[x.fs]>dis[u]+x.sc)
				f=1;
	}
	if(f)cout<<"Cycles exists\n";
	else cout<<"Cycle doesn't exist\n";

	return f;
}
