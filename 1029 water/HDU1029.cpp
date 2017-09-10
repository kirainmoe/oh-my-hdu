/**
* HDU1029 水题，谁说是 DP 的给我出来我保证打不死你 
* 明明是这么简单的计数题！！ 
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
