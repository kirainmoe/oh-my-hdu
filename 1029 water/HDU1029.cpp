/**
* HDU1029 ˮ�⣬˭˵�� DP �ĸ��ҳ����ұ�֤������ 
* ��������ô�򵥵ļ����⣡�� 
*/
#include <bits/stdc++.h> 
const int MAXN = 1e6 + 5;
int data[MAXN];
int main()
{
  int n, flag;
  while (scanf("%d", &n) != EOF)
  {
    bool state = true;
    flag = (n + 1) / 2;
    
    memset(data, 0, sizeof(data));
    
    for (int i = 0; i < n; i++)
    {
      int x;
      scanf("%d", &x);
      data[x]++;
      if (data[x] >= flag && state)
      {
        printf("%d\n", x);
        state = false;
      }
    }
  }
  return 0;
}
