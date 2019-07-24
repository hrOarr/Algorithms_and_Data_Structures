void _part1(int n,int c)
{
    for(int i=1;i<(1<<n);i++)
    {
        int d=1;bool f=1;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                if(d>(k/A[j+c]))
                {
                    f=0;break;
                }
                d*=A[j+c];
            }
        }
        if(f)B.push_back(d);
    }
}
void _part2(int n,int c)
{
    for(int i=1;i<(1<<n);i++)
    {
        int d=1;bool f=1;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                if(d>(k/A[j+c]))
                {
                    f=0;break;
                }
                d*=A[j+c];
            }
        }
        if(f)C.push_back(d);
    }
}
int main()
{
    _part1(n/2,0);
    _part2(n-n/2,n/2);
    sort(C.begin(),C.end());
    for(auto x:B)
    {
        auto hi=upper_bound(C.begin(),C.end(),k/x);
        cnt+=(hi-C.begin());
    }
}
