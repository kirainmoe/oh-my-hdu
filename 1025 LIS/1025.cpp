/**
* HDU1025 DP, LIS
* 想到了 LIS…… orz 但是不会写 nlogn 的做法，所以 n^2 做法完美 TLE……然后是各种 WA 和 PE…… 
* 其实 n^2 和 nlogn 的 LIS 解法区别就在于二分的优化啦
* 
* 附 nlogn 版的 LIS 写法：
* 设 LIS[MAXN] 为此数列的取得 LIS 最大值时的 LIS 一种可能的情况；
* 首先把 LIS 数组设为 INF：fill(LIS + 1， LIS + 1 + n, INF) ;
* 然后遍历数列，利用 lower_bound 函数二分查找到 LIS 中第一个不大于 a[i] 的值的位置 pos，
* 然后把 LIS[pos] 设为 a[i]. 也即 *lower_bound(LIS + 1, LIS + 1 , n, a[i]) = a[i];
* 最后统计 LIS 中不是 INF 的值的个数就可以了，即 ans = lower_bound(LIS + 1, LIS + 1 + n, INF); 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5 * 1e5 + 10;
const int INF = 1e9 + 10;

int n;
int ans = 0, kases = 0;
int maps[MAXN];
int dp[MAXN];
int LIS[MAXN];
int main()
{
  while (scanf("%d", &n) == 1)
  {
    kases++;
    
    // read data
    for (int i = 1; i <= n; i++)
    {
      int x, y;
      scanf("%d%d", &x, &y);
      maps[x] = y;
    }
    
    // initialize
    for (int i = 0; i <= n; i++)
    {
      dp[i] = 0;
      LIS[i] = INF;
    }
    dp[0] = 0;
    
    // LIS
    for (int i = 1; i <= n; i++)
    {
      *lower_bound(LIS + 1, LIS + 1 + n, maps[i]) = maps[i];
    }
    ans = lower_bound(LIS + 1, LIS + 1 + n, INF) - LIS - 1;
    
    printf("Case %d:\n", kases);
    printf("My king, at most %d ", ans);
    if (ans == 1)
    {
      printf("road can be built.\n");
    }
    else
    {
      printf("roads can be built.\n");
    }
    printf("\n");
  }
  
  return 0;
}
