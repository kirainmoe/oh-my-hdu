/**
* HDU1005
* �ã��ԣ�����������֪��Ϊʲô�������� RE��
* �µ��������ǵ��ƣ��������Ƶ�ʱ������ 7 ���ͷ����ˡ���
* ��Ϊģ�� 7������ f(i-1) �� f(i) ����� 49 �������Ҳ������� 49 �ξ�����һ��ѭ����
* Ȼ����������� 
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
