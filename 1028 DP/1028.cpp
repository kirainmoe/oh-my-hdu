/**
* HDU1028
* dp[i][j] ��ʾ������ i ��Ϊ j �ε�ʱ�������ܵķ�����
* ��ô��
* 1.�� i < j ��ʱ����Ϊ���ֻ�ܷ�Ϊ i �Σ��� dp[i][j] = dp[i][i];
* 2.�� i = j ��ʱ�򣬰� i ��Ϊ j �ε�ʱ����ڰ� i ��Ϊ j-1 �ε�ʱ������ֵ�ټ� 1����� 1 ���ǰ� i �ֳ� i �� 1 ���������
* 3.�� i > j ��ʱ��dp[i][j] = dp[i][j-1] + dp[i-j][j], ��ʱ����ڰ� i ��Ϊ j-1 �ε����ֵ�Ͱ� i-j ��Ϊ j ��ʱ�����ֵ������� i - j ��˼���ǰ� j �ֳ� j �� 1 ֮�� i-j ��ȡ�õĽ���� 
* ��һ����ⷽ����dp[i][j] ��ʾ������ i �ò����� j ������ʾ��ʱ���ܵõ��ķ��� 
* (Ҳ��)
*/ 

#include <bits/stdc++.h>
const int MAXN = 120 + 5;
int n;
int dp[MAXN][MAXN];

int main()
{
  while (scanf("%d", &n) != EOF)
  {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i < j)
        {
          dp[i][j] = dp[i][i];
        }
        if (i == j)
        {
          dp[i][j] = dp[i][j-1] + 1;
        }
        if (i > j)
        {
          dp[i][j] = dp[i][j-1] + dp[i-j][j];
        }
      }
    }
    printf("%d\n", dp[n][n]);
  }
  return 0;
}
