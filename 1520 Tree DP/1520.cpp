/**
* HDU1520 ���� DP ���� 
* emmm...���������е�һ������ DP����
* ������и��ܿӵĵط�������һ�������кö�������񣬵�����ʲ��ô������û��˵�� 
* Ȼ���ҽ��� 7 �黹�ǲ�֪��Ϊʲô WA �ġ������˸� std һ�����Բ�Ҫ����������ݡ���
*  
* �� dp[i][0] Ϊ������� i ���˵����ֵ�� 
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
