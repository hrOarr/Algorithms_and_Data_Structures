// Any number is Ra-one if the Difference between Sum of digits at even location and Sum of digits at odd location is One
// Count Ra-one numbers in range
#include "bits/stdc++.h"
using namespace std;
int dp[15][500],Dig[15];
int dfs( int Pos,int Sum,bool Lim )
{
    if( Pos==0 )return (Sum==1);
    int &Ret = dp[Pos][Sum];
    if( !Lim&&Ret!=-1 )return Ret;
    int Up = 9;
    if( Lim )Up = Dig[Pos];
    int Now = 0;
    for(int i=0;i<=Up;i++)
    {
        int a;
        if( Pos&1 )a = -1;
        else a = 1;
        Now += dfs( Pos-1,Sum+i*a,Lim&&i==Up );
    }
    if(!Lim)Ret = Now;
    return Now;
}
int Ans(int x)
{
    int id = 0;
    while(x)Dig[++id] = x%10,x /= 10;
    return dfs( id,0,true );
}
int main()
{
    memset(dp,-1,sizeof dp);
    int tc;cin>>tc;
    while(tc--)
    {
        int a,b;cin>>a>>b;
        cout<<Ans(b)-Ans(a-1)<< "\n";
    }

    return 0;
}
