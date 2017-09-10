/**
* HDU3182 ״̬ѹ�� DP 
* QAQ����д�ĵڶ���״̬ѹ�� DP �⡭�� 
* ��Ƚ���һ��Ļ�������˼·��̫һ������һ������ͨ����ǰ״̬��ǰһ��״̬����һ����ͨ����ǰ״̬����һ��״̬
* �����ֽⷨ��һ���Ǳ� DP �߼�֦���� cost ̫���ֱ�Ӽ�������һ����һ���� DP �꣬Ȼ����������ж�״̬�Ƿ�Ϸ������
* DP���̣�dp[i | j].val = dp[i].val + items[j].val, ��Ҫ��֤ cost ����Ŀ���޶���Χ�� 
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
