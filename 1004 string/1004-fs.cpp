/**
* HDU1004 简单的字符串计数问题 OvO 
* 没什么好写的样子，就是读入数据然后排个序然后统计一下最大值输出，然后……没有然后了。 
*/ 

#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 1010;
string balloons[MAXN];
int main()
{
  freopen("1004.in", "r", stdin);
  freopen("1004.out", "w", stdout);
  
  int num;
  int maximum, tmp, handle;
  
  while (scanf("%d", &num) != EOF && num != 0)
  { 
    for (int i = 0; i < num; i++)
    {
      cin >> balloons[i];
    }
    sort(balloons, balloons + num);
    
    maximum = 0, tmp = 0, handle = 0;
    for (int i = 1; i < num; i++)
    {
      if (balloons[i] != balloons[i-1])
      {
        tmp = 1;
      }
      else
      {
        tmp++;
      }
      
      if (tmp > maximum)
      {
        maximum = tmp;
        handle = i;
      }
    }
    cout << balloons[handle]  << endl;
  }
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}
