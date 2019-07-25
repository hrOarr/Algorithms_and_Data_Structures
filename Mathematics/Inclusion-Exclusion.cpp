// how many ways you can take 4 integers from the N numbers such that their GCD is 1

#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
const int N = 1e4+4;
ll nCr[N],Frq[N],Cnt[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    nCr[4] = 1;
    for(int i=5;i<N;i++)
        nCr[i] = nCr[i-1]*i / (i-4);
    ll tc,k=0;cin>>tc;
    while(tc--)
    {
        ll n;cin>>n;
        ll MX = 0;
        memset( Frq,0,sizeof Frq );
        while(n--)
        {
            ll x;cin>>x;
            MX = max( MX,x );
            Frq[x]++;
        }
        for(int i=1;i<=MX;i++)
        {
            Cnt[i] = 0;
            for(int j=i;j<=MX;j+=i)
                Cnt[i] += Frq[j];
            Cnt[i] = nCr[ Cnt[i] ];
        }
        for(int i=MX;i;i--)
        {
            for(int j=i+i;j<=MX;j+=i)
                Cnt[i] -= Cnt[j];
        }
        cout<< "Case "<<++k<< ": "<<Cnt[1]<< "\n";
    }

    return 0;
}

// So, at first they will choose a number N which represents possible life-time. Then there will be an integer M indicating the total number of predators. The next M integers represent the life-cycle of each predator. The numbers in the range from 1 to N which are not divisible by any of those M life-cycles numbers will be considered for cicada's safe-emerge year.

int main()
{
    ll tc,k=0;cin>>tc;
    while(tc--)
    {
        ll n,m;cin>>n>>m;
        ll Arr[m+2],Cnt = 0;
        for(int i=0;i<m;i++)cin>>Arr[i];
        for(int i=1;i<(1<<m);i++)
        {
            int sign = __builtin_popcount(i)&1;
            ll Now = 1;
            if( sign )sign = 1;
            else      sign = -1;
            for(int j=0;j<m;j++)
            {
                if( i&(1<<j) )
                {
                    ll gcd = __gcd( Arr[j],Now );
                    Now = (Now*Arr[j])/gcd;
                }
            }
            Cnt += (sign*(n/Now));
        }
        cout<< "Case "<<++k<< ": "<<n-Cnt<< "\n";
    }
    return 0;
}
