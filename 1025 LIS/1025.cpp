/**
* HDU1025 DP, LIS
* �뵽�� LIS���� orz ���ǲ���д nlogn ������������ n^2 �������� TLE����Ȼ���Ǹ��� WA �� PE���� 
* ��ʵ n^2 �� nlogn �� LIS �ⷨ��������ڶ��ֵ��Ż���
* 
* �� nlogn ��� LIS д����
* �� LIS[MAXN] Ϊ�����е�ȡ�� LIS ���ֵʱ�� LIS һ�ֿ��ܵ������
* ���Ȱ� LIS ������Ϊ INF��fill(LIS + 1�� LIS + 1 + n, INF) ;
* Ȼ��������У����� lower_bound �������ֲ��ҵ� LIS �е�һ�������� a[i] ��ֵ��λ�� pos��
* Ȼ��� LIS[pos] ��Ϊ a[i]. Ҳ�� *lower_bound(LIS + 1, LIS + 1 , n, a[i]) = a[i];
* ���ͳ�� LIS �в��� INF ��ֵ�ĸ����Ϳ����ˣ��� ans = lower_bound(LIS + 1, LIS + 1 + n, INF); 
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
