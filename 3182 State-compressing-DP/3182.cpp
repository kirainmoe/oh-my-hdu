/**
* HDU3182 状态压缩 DP 
* QAQ这周写的第二道状态压缩 DP 题…… 
* 相比较上一题的话这道题的思路不太一样，上一道题是通过当前状态推前一个状态，这一题是通过当前状态推下一个状态
* 有两种解法，一种是边 DP 边剪枝，把 cost 太大的直接剪掉；另一种是一次性 DP 完，然后最后再来判断状态是否合法并输出
* DP方程：dp[i | j].val = dp[i].val + items[j].val, 需要保证 cost 在题目的限定范围内 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
const int MAXS = 1 << 15;
const int INF = 1e9 + 7;

struct Hamburger {
  int val;
  int cost;
  int dep;
  int deps[15];
};
Hamburger items[MAXN];

struct State {
  int val;
  int cost;
};
State dp[MAXS];

int cases;
int n, e;

int main()
{
  scanf("%d", &cases);
  
  while (cases--)
  {
    memset(items, 0, sizeof(items));
    memset(dp, -1, sizeof(dp));
    
    scanf("%d%d", &n, &e);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &items[i].val);
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &items[i].cost);
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &items[i].dep);
      if (items[i].dep > 0)
      {
        for (int j = 0; j < items[i].dep; j++)
        {
          scanf("%d", &items[i].deps[j]);
          items[i].deps[j]--;
        }
      }
    } // end read
    
    int end = 1 << n;
    int ans = 0;

    dp[0].cost = 0, dp[0].val = 0;

    for (int i = 0; i < end; i++)
    {
      if (dp[i].cost == -1)
        continue;
        
      for (int j = 0; j < n; j++)
      {
        int cur = 1 << j;
        if (!(i & cur))
        {
          int next = i | cur;
          
          bool flag = true;
          if (items[j].dep > 0)
          {
            for (int x = 0; x < items[j].dep; x++)
            {
              int depState = 1 << items[j].deps[x];
              if (!(i & depState)) {
                flag = false;
                break;
              }
            } // for x = 0 -> items[j].dep
          } // if items[j].dep > 0
          
          if (flag)
          {
            dp[next].val = dp[i].val + items[j].val;
            dp[next].cost = dp[i].cost + items[j].cost;
          }
          
        } // if i & cur
      } // for j = 0 -> n
    } // for i = 1 -> end

    for (int i = 0; i < end; i++)
    {
      if (dp[i].cost <= e)
        ans = max(ans, dp[i].val);
    }
  
    printf("%d\n", ans);

  }
  
  return 0;
}
