int dx[]={+1,-1,+0,+0},dy[]={+0,+0,+1,-1};string s[1010];
int n,m,k,x1,y1,x2,y2,vis[1010][1010],dis[1010][1010];
bool Ok(int x,int y)
{
    return (x>=0&&x<n&&y>=0&&y<m);
}
void _bfs()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
           dis[i][j]=inf;
    dis[x1][y1]=0;
    deque<pair<int,pair<int,int> > >q1;
    for(int i=0;i<4;i++)
    {
        int k=1,x,y;
        while(k<=1)
        {
            x=x1+k*dx[i],y=y1+k*dy[i];
            if(!Ok(x,y)||s[x][y]=='*')break;k++;
            dis[x][y]=0;q1.push_back(mp(i,mp(x,y)));
        }
    }
    while(!q1.empty())
    {
        auto r=q1.front();q1.pop_front();
        int x=r.S.F,y=r.S.S,turn=r.F;
        for(int i=0;i<4;i++)
        {
            int k=1,xx,yy;
            while(true)
            {
                xx=x+k*dx[i],yy=y+k*dy[i];
                if(!Ok(xx,yy)||s[xx][yy]=='*'||dis[xx][yy]<=dis[x][y]+(turn!=i))break;
                dis[xx][yy]=dis[x][y]+(turn!=i); // 0 or 1
                if(turn!=i)q1.push_back(mp(i,mp(xx,yy))); // 1
                else q1.push_front(mp(i,mp(xx,yy))); // 0
                k++;
            }
        }
    }
}