#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
const ll N = 511,lg = 10,inf = 1234567890;

int n;
int tbl[N][lg][N];
int a1[N][N];

int main()
{
    int tc; scanf("%d", &tc);
    int k = 0;
    while (tc--){
        int q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i ++){
            for (int j = 0; j < n; j ++){
                scanf("%d", &a1[i][j]);
            }
        }
        memset( tbl, 0, sizeof tbl );
        for (int i = 1; i <= n; i ++){
            for (int j = 0; j < n; j ++){
                tbl[i][0][j] = a1[i][j];
            }
        }

        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= lg; j ++){
                for (int k = 0; (k+(1<<j)) <= n; k ++){
                    tbl[i][j][k] = max( tbl[i][j-1][k],tbl[i][j-1][(k+(1<<(j-1)))] );
                }
            }
        }

        printf("Case %d:\n", ++k);
        while (q--){
            int a,b,s; scanf("%d%d%d", &a, &b, &s);
            int x1 = a, y1 = b;
            int x2 = a+s-1, y2 = b+s-1;
            int mx = 0; y1 --, y2 --;
            for (int i = x1; i <= x2; i ++){
                 int k = y1;
               for (int j = lg; j >= 0; j --){
                  if ( (k+(1<<j)-1) <= y2 ){
                    mx = max( mx,tbl[i][j][k] );
                    k += (1<<j);
                  }
               }
            }
            printf("%d\n", mx);
        }

    }


    return 0;
}
