struct Q
{
	int x1,y1;
	int x2,y2;
};
void updtBIT(int T[][N+1],int x,int y,int vl)
{
	for(;x<=N;x+=(x&-x))
	{
		for(;y<=N;y+=(y&-y))
			T[x][y]+=vl;
	}
}
// A function to get sum from (0, 0) to (x, y)
int getSum(int T[][N+1],int x,int y)
{
	int rt=0;
	for(;x>0;x-=x&-x)
	{
		for(;y>0;y-=y&-y)
			rt+=T[x][y];
	}
	return rt;
}
void build(int mat[][N],int aux[][N+1])
{
	for(int i=0;i<=N;i++)memset(aux[i],0,sizeof aux[i]);
	for(int j=1;j<=N;j++)
		for(int i=1;i<=N;i++)
			aux[i][j]=mat[N-j][i-1];
}
void build2DBIT(int mat[][N],int T[][N+1])
{
	int aux[N+1][N+1];build(mat,aux);
	for(int i=1;i<=N;i++)memset(T[i],0,sizeof T[i]);
	for(int j=1;j<=N;j++)
	{
		for(int i=1;i<=N;i++)
		{
			int v1=getSum(T,i,j);
			int v2=getSum(T,i,j-1);
			int v3=getSum(T,i-1,j-1);
			int v4=getSum(T,i-1,j);
			updtBIT(T,i,j,aux[i][j]-(v1-v2-v4+v3));
		}
	}
}
void answerQueries(Q q[],int m,int T[][N+1])
{
	for(int i=0;i<m;i++)
	{
		int x1=q[i].x1+1;
		int y1=q[i].y1+1;
		int x2=q[i].x2+1;
		int y2=q[i].y2+1;
		int rs=getSum(T,x2,y2)-getSum(T,x2,y1-1)-getSum(T,x1-1,y2)+getSum(T,x1-1,y1-1);
		cout<<rs<<"\n";
	}
}
