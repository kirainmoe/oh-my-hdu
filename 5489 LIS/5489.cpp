/**
* HDU5489 LIS Solution 1:
* 因为要从数列中删除一些数之后求 LIS，然后就是我们枚举删除的数的终点，然后对终点右边的第一个数为起点求一次 LIS 
* 然后再从最左边到删除的起点求一次 **最大的数不超过终点右边第一个数** 的 LIS 
* 从右往左的这个 LIS 必须在枚举起点之前预处理求出，所以： 
* 从右往左求 LIS 可以用负数的方法来做，然后倒着求回来，一直从 n 求到 l 为止。
*/
#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9 + 7;

int kases, tmp;
int n, l;
int a[MAXN], b[MAXN], dp[MAXN], LIS[MAXN];

int main()
{
  scanf("%d", &kases);
  
  while (kases--)
  {
    tmp++;
    scanf("%d%d", &n, &l);
    
    fill(dp, dp + MAXN, INF);
    
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      b[i] = -a[i];
    }
    
    // reverse LIS
    int pos = 0;
    fill(LIS, LIS + MAXN, INF);
    
    for (int i = l; i >= l; i--)
    {
      pos = lower_bound(LIS, LIS + n, b[i]) - LIS;
      LIS[pos] = b[i];
      dp[i] = pos + 1;
    }
    
    int ans = 0, maxlen = 0;
    fill(LIS, LIS + MAXN, INF);
    for (int i = l; i < n; i++)
    {
      pos = lower_bound(LIS, LIS + n, a[i]) - LIS;      // from left to right
      ans = max(ans, pos + 1 + dp[i] - 1);        // >=

      pos = lower_bound(LIS, LIS + n, a[i - l]) - LIS;    // update left LIS
      LIS[pos] = a[i-l];
      maxlen = max(maxlen, pos + 1);
    }
    ans = max(ans, maxlen);
    printf("Case #%d: %d\n", tmp, ans);
  }
  
  return 0;
}
