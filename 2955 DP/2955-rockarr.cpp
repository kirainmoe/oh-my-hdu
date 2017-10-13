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
double dp[MAXS];

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

    dp[0] = 1.00000;
    for (int i = 1; i <= n; i++)
    {
      for (int j = sum; j >= 0; j--)
      {
        dp[j] = max(dp[j], dp[j-cash[i]] * (1.000000 - rates[i]));
      }
    }

    for (int i = sum; i >= 0; i--)
    {
      if (dp[i] > (1.00000 - limit)) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}