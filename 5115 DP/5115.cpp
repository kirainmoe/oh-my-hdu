#include <cstdio> 
#include <cstring>
#include <algorithm>
#define LL long long

using namespace std;
const int MAXN = 210;
const LL INF = (1 << 30);
int n, t;
LL a[MAXN], b[MAXN];
LL dp[MAXN][MAXN];

int main()
{
    scanf("%d", &t);
    for (int x = 1; x <= t; x++)
    {
        printf("Case #%d: ", x);
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        
        scanf("%d", &n);
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%I64d", &a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%I64d", &b[i]);
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                dp[i][j] = INF;
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 0;
            dp[i][i] = a[i] + b[i-1] + b[i+1];
        }
        
        for (int l = 1; l <= n; l++)
        {
            for (int s = 1; s + l - 1 <= n; s++)
            {
                int t = s + l - 1;
                for (int k = s; k <= t; k++)
                {
                    dp[s][t] = min(dp[s][t], dp[s][k-1] + dp[k+1][t] + a[k] + b[s-1] + b[t+1]);
                }
            }
        }
        
        printf("%I64d\n", dp[1][n]);
    }
    return 0;
} 
