// This is WA code.

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 120;
const int MAXS = 100 * 100 + 100;
int cases, n, sum;
int ans = 0;
int cash[MAXN];
double limit;
double rates[MAXN];
double dp[MAXS][MAXN];

void init()
{
  n = 0;
  sum = 0;
  ans = 0;
  limit = 0.0;
  memset(cash, 0, sizeof cash);
  memset(rates, 0, sizeof rates);
  memset(dp, 0, sizeof dp);
}

int main()
{
  scanf("%d", &cases);
  while (cases--)
  {
    init();

    scanf("%lf%d", &limit, &n);
    for (int i = 1; i <= n; i++)
    {
      scanf("%d%lf", &cash[i], &rates[i]);
      sum += cash[i];
    }

    for (int i = 0; i <= n; i++)
    {
      /*
      for (int j = 0; j < cash[i]; j++)
      {
        printf("%d %d\n", i, j);
        dp[i][j] = 1.00000;
      }
      */
     dp[i][0] = 1.0000;
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = sum; j >= 0; j--)
      {
        // printf("%d, %d, %.2lf \n", i, j, dp[i][j]);
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-cash[i]] * (1.000000 - rates[i]));
      }
    }
    /*
    for (int i = 0 ; i <= n; i++)
    {
      for (int j = 0; j <= sum; j++)
      {
        printf("%.2lf ", dp[i][j]);
      }
      printf("\n");
    }
    */

    for (int i = sum; i >= 0; i--)
    {
      if (dp[n][i] > (1.00000 - limit)) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}