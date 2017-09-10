/**
* HDU1028
* dp[i][j] 表示把整数 i 分为 j 段的时候最多可能的方案数
* 那么：
* 1.当 i < j 的时候，因为最多只能分为 i 段，则 dp[i][j] = dp[i][i];
* 2.当 i = j 的时候，把 i 分为 j 段的时候等于把 i 分为 j-1 段的时候的最大值再加 1，这个 1 就是把 i 分成 i 个 1 的那种情况
* 3.当 i > j 的时候，dp[i][j] = dp[i][j-1] + dp[i-j][j], 这时候等于把 i 分为 j-1 段的最大值和把 i-j 分为 j 段时的最大值。这里的 i - j 意思就是把 j 分成 j 个 1 之后 i-j 能取得的结果。 
* 另一种理解方法：dp[i][j] 表示把整数 i 用不超过 j 的数表示的时候能得到的方案 
* (也许)
*/ 

#include <bits/stdc++.h>
const int MAXN = 120 + 5;
int n;
int dp[MAXN][MAXN];

int main()
{
  while (scanf("%d", &n) != EOF)
  {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i < j)
        {
          dp[i][j] = dp[i][i];
        }
        if (i == j)
        {
          dp[i][j] = dp[i][j-1] + 1;
        }
        if (i > j)
        {
          dp[i][j] = dp[i][j-1] + dp[i-j][j];
        }
      }
    }
    printf("%d\n", dp[n][n]);
  }
  return 0;
}
