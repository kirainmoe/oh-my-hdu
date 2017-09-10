/**
* HDU1024 DP ������� m ����� 
* emmm...��������һ���⣬��ͬʱҲ��һ�����⣬����Ļ���ͬĿ¼�µ���� TXT �ɡ��� 
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
    // ö��������������ù������齵��ά�� 
    for (int i = 1; i <= m; i++)
    {
      curmax = -INF;
      // ö�ٴ����е� i ��������ȡ�����ֵ����� 
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
