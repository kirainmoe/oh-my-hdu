/**
* HDU1003 ��������Ӷκͣ�ѯ��λ�õ�ʱ��࿪������¼����λ�õ����� left[], right[]
* Ȼ����� dp ����Ϊ dp[i] = max(dp[i-1]+a[i], a[i])
* ��Ϊ�� dp[i-1] �Ǹ�����ʱ��dp[i-1] + a[i] ��ȻС�� a[i] 
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
      // ����������ʱ�����¼��� 
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
    
    int maximum = -INF;   // ά�����ֵ
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
