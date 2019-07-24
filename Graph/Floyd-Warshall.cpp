void FloydWarshall(int n)
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=inf;
    while(m--)
    {
        int u,v,w;cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
    }
    FloydWarshall(n);
}
