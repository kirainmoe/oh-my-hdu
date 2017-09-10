/**
* HDU1024 DP 最大连续 m 区间和 
* emmm...很难理解的一道题，但同时也是一道好题，具体的话看同目录下的题解 TXT 吧…… 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
const int INF = 1e9 + 7;

int n, m;
int a[MAXN];
int dp[MAXN];
int premax[MAXN];

int main()
{
  while (scanf("%d%d", &m, &n) != EOF)
  {
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
    }
    
    for (int i = 0; i <= n; i++)
    {
      dp[i] = 0;
      premax[i] = 0;    // ?
    }
    
    int curmax;
    // 枚举区间个数，采用滚动数组降低维度 
    for (int i = 1; i <= m; i++)
    {
      curmax = -INF;
      // 枚举从已有的 i 个区间中取得最大值的情况 
      for (int j = i; j <= n; j++)
      {
        dp[j] = max(dp[j-1] + a[j], premax[j-1] + a[j]);
        premax[j-1] = curmax;
        curmax = max(curmax, dp[j]);
      }
    }
    
    printf("%d\n", curmax);
  }
  return 0;
}
