/**
* HDU1003 最大连续子段和，询问位置的时候多开两个记录区间位置的数组 left[], right[]
* 然后就是 dp 方程为 dp[i] = max(dp[i-1]+a[i], a[i])
* 因为当 dp[i-1] 是负数的时候，dp[i-1] + a[i] 显然小于 a[i] 
*/

#include <bits/stdc++.h> 
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int n, sn;
int a[MAXN];
int dp[MAXN];
int left[MAXN], right[MAXN];

void init()
{
  for (int i = 0; i < MAXN; i++)
  {
    dp[i] = -INF;
    left[i] = 0;
    right[i] = 0;
  }
}

int main()
{
  freopen("1003.in", "r", stdin);
  freopen("1003.out", "w", stdout);

  scanf("%d", &n);
  sn = n;
  
  int tmp = 1;
  while (sn--)
  {
    printf("Case %d:\n", tmp++);
    init();
    
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
      scanf("%d", &a[i]);
    }
    
    dp[0] = a[0], left[0] = 0, right[0] = 0;
    for (int i = 1; i <= num; i++) 
    {
      // 遇到负数的时候重新计数 
      if (dp[i-1] < 0)
      {
        left[i] = right[i] = i;
        dp[i] = a[i];
        continue;
      }

      dp[i] = dp[i-1] + a[i];
      left[i] = left[i-1];
      right[i] = i;
    }
    
    int maximum = -INF;   // 维护最大值
    int l, r;
    for (int i = 0; i < num; i++) 
    {
      if (dp[i] > maximum)
      {
        maximum = dp[i];
        l = left[i], r = right[i];
      }
    }
    
    printf("%d %d %d\n", maximum, l+1, r+1);
    
    if (tmp-1 != n)
    {
      printf("\n");
    }
  }

  fclose(stdin);
  fclose(stdout);

  return 0;
}
