// Couple of deductions about bitwise XOR necessary for understanding the Optimal Strategy:
// If the XOR sum of ‘n’ numbers is already zero then
// there is no possibility to make the XOR sum zero
// by single reduction of a number.

// If the XOR sum of ‘n’ numbers is non-zero then there is at least
// a single approach by which if you reduce a number, the XOR sum is zero.

#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
const ll N=1e6+6,inf=1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc=1,t=0;
    while(tc--){
        int piles[] = {7, 10, 3, 2, 2, 2, 15, 12};
        int xorsum=0,n=sizeof(piles)/sizeof(piles[0]);
        for(int i=0;i<n;i++){
            xorsum ^= piles[i];
        }
        if(xorsum)cout<<"Player 1 wins\n";
        else cout<<"Player 2 wins\n";
    }

    return 0;
}

// special cases of Misere Nim game
// it happens when all piles include odd number of 1-stone (exp. n=5, piles[]={1,1,1,1,1}
// and the result will be reverse (if non-zero xor-sum then player 2 wins, otherwise player 1 wins
