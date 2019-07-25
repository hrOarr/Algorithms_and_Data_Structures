// uva prime ring problem
void bcktrck(int now)
{
    if(now==n)
    {
        if( !Prime(1+Arr[n-1]) )
            return;
        for(int i=0;i<n;i++)
        {
            if(i)cout<< " ";
            cout<<Arr[i];
        }
        cout<< "\n";
        return ;
    }
    for(int i=2;i<=n;i++)
    {
        if( !vis[i]&&Prime(i+Arr[now-1]) )
        {
            vis[i] = 1;
            Arr[now] = i;
            bcktrck(now+1);
            vis[i] = 0;
        }
    }
}

// backtracking with pruning
void bcktrck( int idx,int cur )
{
    if(cur>=mn)return;
    if( idx==n )
    {
        if(Arr[idx]>=0)return;
        mn = cur;
        for(int i=2;i<=n-1;i++)
            res[i] = now[i];
        return;
    }
    int st = Arr[idx-1]/b;
    int mx = st;
    mx = max(mx,Arr[idx]/a);
    mx = max(mx,Arr[idx+1]/b);
    for(int i=0;i<=mx+1;i++)
    {
        if(Arr[idx-1]-i*b>=0)continue;
        Arr[idx] -= i*a;
        Arr[idx-1] -= i*b;
        Arr[idx+1] -= i*b;
        now[idx] = i;
        bcktrck(idx+1,cur+i);
        Arr[idx] += i*a;
        Arr[idx-1] += i*b;
        Arr[idx+1] += i*b;
        now[idx] = 0;
    }
}
