/*
f(0) = a
f(1) = b
f(n) = f(n-1) + f(n-2), n > 1
Given the values of a, b, you have to find the last m digits of f(n).
*/

//#include "bits/stdc++.h"
#include "cstdio"
#include "cstring"
//using namespace std;

typedef long long int ll;
const ll N = 1e6+6;
ll mod=1e9+7;
ll base[2][2]={{1,1},{1,0}},unit[2][2]={{1,0},{0,1}};
void multiply(ll arr[2][2],ll brr[2][2],int n,int m)
{
    ll mul[2][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mul[i][j]=0;
            for(int k=0;k<m;k++)
            {
                mul[i][j]+=(arr[i][k]*brr[k][j]);
                mul[i][j]%=mod;
            }
        }
    }
    memcpy(arr,mul,sizeof mul);
}
void matrix_expo(ll res[2][2],ll p,int n,int m)
{
   ll tmp[2][2];
   memcpy(tmp,base,sizeof base);
   memcpy(res,unit,sizeof unit);
   while(p>0)
   {
       if(p&1)multiply(res,tmp,n,m);
       multiply(tmp,tmp,n,m);
       p>>=1;
   }
}
ll pow(ll n,ll m)
{
    if(m==0)return 1;
    return pow(n,m-1)*n;
}
int main()
{
    ll n,a,b,m,k=0,tc;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        if(n<2)
        {
            printf("Case %lld: ",++k);
            if(n==0)printf("%lld\n",a);
            else printf("%lld\n",b);
            continue;
        }
        mod=pow(10,m);
        ll F[2][2];
        matrix_expo(F,n-1,2,2);
        ll x=((F[0][0]*b)%mod+(F[0][1]*a)%mod)%mod;
        if(n==0)x=a;
        else if(n==1)x=b;
        printf("Case %lld: %lld\n",++k,x);
    }

    return 0;
}
