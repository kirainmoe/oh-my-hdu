/**
* HDU1069 经典 DP
* 最开始的思路是……设一个四维的状态…反正数据范围这么小是吧（gun 后来写了好久写不下去了 
* 查了一发题解，随便点开一个，看到第一句话：先把 x 排序，然后把 y 排序……
* 会了…… 
* 那么，首先输入一组 xyz，然后排序一下，选择其中两个当做 width 和 length，然后最后一个数当 height 
* 把 x, y 分别按照从大到小的顺序排序一遍，然后对 z 求满足第 i 层的 x, y 小于第 i-1 层的 x, y 时的最大 z 之和就好了
* 转移方程：dp[i] = dp[j] + block[i].height, 其中 j = 0...i-1
* 嘛，顺序枚举 j 似乎会 WA，所以 j 要从 i-1 倒回去。 
*/

#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 35 * 6 + 10;
struct Block {
  int x, y, z;
};
Block b[MAXN];
int T, kases = 0;
int size = 0, ans = 0;
int dp[MAXN];

bool cmp(const Block a, const Block b)
{
  if (a.x > b.x)
    return true;
  if (a.x == b.x && a.y > b.y)
    return true;
  return false;
}

int main()
{
  while (scanf("%d", &T) != EOF && T != 0)
  {    
    size = 0, ans = 0;
    memset(b, 0, sizeof(b));
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < T; i++)
    {
      int tx, ty, tz;
      scanf("%d%d%d", &tx, &ty, &tz);
      int arr[3] = {tx, ty, tz};
      
      sort(arr, arr + 3);
      
      // permutation
      b[size].x = arr[0], b[size].y = arr[1], b[size++].z = arr[2];
      b[size].x = arr[0], b[size].y = arr[2], b[size++].z = arr[1];
      b[size].x = arr[1], b[size].y = arr[2], b[size++].z = arr[0];
      
      sort(b, b+size, cmp);
    }
    
    for (int i = 0; i < size; i++)
    {
      dp[i] = b[i].z;
      for (int j = i - 1; j >= 0; j--)
      {
        if (b[i].x < b[j].x && b[i].y < b[j].y) {
          dp[i] = max(dp[j] + b[i].z, dp[i]);
        }
      }
      ans = max(ans, dp[i]);
    }
    printf("Case %d: maximum height = %d\n", ++kases, ans);
  }
  return 0;
}
