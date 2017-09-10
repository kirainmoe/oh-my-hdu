/**
* HDU1005
* 好！迷！啊！我至今不知道为什么那样做会 RE！
* 猜到了这题是递推，但是手推的时候推了 7 个就放弃了……
* 因为模了 7，所以 f(i-1) 和 f(i) 最多有 49 种情况，也就是最多 49 次就遇到一个循环节
* 然后就做完啦。 
*/
#include <bits/stdc++.h> 
int arr[55];
int main()
{
  arr[0] = 1, arr[1] = 1;
  
  int a, b, n;
  int pot = 0;
  while (scanf("%d%d%d", &a, &b, &n) != EOF && n != 0)
  {
    int pot;
    for (int i = 2; i <= 54; i++)
    {
      arr[i] = (a * arr[i-1] + b * arr[i-2]) % 7;
      if (arr[i] == 1 && arr[i-1] == 1)
      {
        pot = i;
        break;
      }
    }
    
    n = n % (pot-1);
    
    if (n == 0)
    {
      printf("%d\n", arr[pot-2]);
    }
    else
    {
      printf("%d\n", arr[n-1]);
    }
  }
  return 0;
}
