/**
* 数塔做法：联想一下数字三角形 
* dp[i][j] 还是表示第 i 秒在第 j 个位置能取到的最大值
* 不同的是要逆推，并且可以直接覆盖掉之前的值（因为计算完就没有用了） 
* dp[i][j] =  max(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]) + dp[i][j];
*/ 

#include <bits/stdc++.h> 
using namespace std;
const int MAXT = 1e5 + 10;
const int MAXP = 11;

int n, mt, ans = 0;
int pies[MAXT][MAXP];

int main()
{
  freopen("1176.in", "r", stdin);
  freopen("1176.std.out", "w", stdout);

  while (scanf("%d", &n) != EOF && n)
  {
    memset(pies, 0, sizeof(pies));
    ans = 0;
    for (int i = 0; i < n; i++)
    {
      int x, t;
      scanf("%d%d", &x, &t);
      pies[t][x]++;
      mt = max(mt, t);
    }
    
    for (int i = mt - 1; i >= 0; i--)
    {
      for (int j = 0; j < MAXP; j++)
      {
        int tmp = pies[i][j];       // current
        pies[i][j] = pies[i+1][j];
        
        if (j > 0) {
          pies[i][j] = max(pies[i+1][j-1], pies[i][j]);
        }
        
        if (j < MAXP - 1) {
          pies[i][j] = max(pies[i+1][j+1], pies[i][j]);
        }
        
        pies[i][j] += tmp;
      }
    }
    
    printf("%d\n", pies[0][5]);
  }
  fclose(stdin);
  fclose(stdout);
  
  return 0;
}
