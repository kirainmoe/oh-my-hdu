/**
* HDU1520 树形 DP 简单题 
* emmm...还是人生中第一题树形 DP……
* 这道题有个很坑的地方就是它一个样例有好多个子任务，但是它什！么！都！没！说！ 
* 然后我交了 7 遍还是不知道为什么 WA 的……找了个 std 一看，卧槽要处理多组数据……
*  
* 设 dp[i][0] 为不邀请第 i 个人的最大值， 
*/ 
#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 6010;
int n;
int rate[MAXN], p[MAXN];
int dp[MAXN][2];
vector<int> T[MAXN];

void dfs(int s)
{
  if (T[s].size() == 0)
  {
    dp[s][1] = rate[s];
    dp[s][0] = 0;
    return;
  }
  
  for (int i = 0; i < T[s].size(); i++)
  {
    int cur = T[s][i];
    dfs(cur);
    dp[s][0] += max(dp[cur][1], dp[cur][0]);
    dp[s][1] += dp[cur][0];
  }
  dp[s][1] += rate[s];
  return;
}

int main()
{
  while (scanf("%d", &n) != EOF)
  {
    memset(rate, 0, sizeof(rate));
    memset(p, 0, sizeof(p));
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i <= MAXN; i++)
    {
      T[i].clear();
    }
    
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &rate[i]);
    }
    
    int x, y;
    while (scanf("%d%d", &x, &y) != EOF && x != 0 && y != 0)
    {
      T[y].push_back(x);
      p[x] = y;
    }
    
    int s;
    for (int i = 1; i <= n; i++)
    {
      if (p[i] == 0)
      {
        s = i;
        break;
      }
    }
    
    dfs(s);
    int ans = max(dp[s][0], dp[s][1]);
    printf("%d\n", ans);    
  }
  return 0;
}
