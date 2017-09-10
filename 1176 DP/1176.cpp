/**
* 做法 1：直接 DP，注意的是不要想太多去检查状态是否合法 ( 
* dp[i][j] 表示第 i 秒的时候站在第 j 个位置能接到的最大馅饼数 
* dp[i][j]  = max(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]) + items[i][j] (如果 j-1 和 j+1 存在)
*/ 

#include <bits/stdc++.h>
using namespace std;

const int MAXT = 1e5 + 10;
const int MAXP = 11;

int n, mt, ans = 0;
int items[MAXT][MAXP];
int dp[MAXT][MAXP];

int cmp(int a, int b, int c)
{
  return max(a, max(b, c));
}

int main()
{
  while (scanf("%d", &n) != EOF && n != 0)
  {
    memset(items, 0, sizeof(items));
    memset(dp, 0, sizeof(dp));
    mt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
      int x, t;
      scanf("%d%d", &x, &t);
      items[t][x]++;
      mt = max(t, mt);
    }
    
    dp[1][4] = items[1][4];
    dp[1][5] = items[1][5];
    dp[1][6] = items[1][6];
    
    for (int i = 2; i <= mt; i++)
    {
      for (int j = 0; j < MAXP; j++)
      {
        dp[i][j] = dp[i-1][j];
        if (j == 0) {
          dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + items[i][j];
        } else if (j == MAXP - 1) {
          dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + items[i][j];
        } else {
          dp[i][j] = cmp(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + items[i][j];
        }
        ans = max(ans, dp[i][j]);
      }
    }
    
    printf("%d\n", ans);
  }
  return 0;
}
