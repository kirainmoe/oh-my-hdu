/**
* HDU1069 ���� DP
* �ʼ��˼·�ǡ�����һ����ά��״̬���������ݷ�Χ��ôС�ǰɣ�gun ����д�˺þ�д����ȥ�� 
* ����һ����⣬���㿪һ����������һ�仰���Ȱ� x ����Ȼ��� y ���򡭡�
* ���ˡ��� 
* ��ô����������һ�� xyz��Ȼ������һ�£�ѡ�������������� width �� length��Ȼ�����һ������ height 
* �� x, y �ֱ��մӴ�С��˳������һ�飬Ȼ��� z ������� i ��� x, y С�ڵ� i-1 ��� x, y ʱ����� z ֮�;ͺ���
* ת�Ʒ��̣�dp[i] = dp[j] + block[i].height, ���� j = 0...i-1
* �˳��ö�� j �ƺ��� WA������ j Ҫ�� i-1 ����ȥ�� 
*/

#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 35 * 6 + 10;
struct Block {
  int x, y, z;
};
Block b[MAXN];
int T, kases = 0;
int size = 0, ans = 0;
int dp[MAXN];

bool cmp(const Block a, const Block b)
{
  if (a.x > b.x)
    return true;
  if (a.x == b.x && a.y > b.y)
    return true;
  return false;
}

int main()
{
  while (scanf("%d", &T) != EOF && T != 0)
  {    
    size = 0, ans = 0;
    memset(b, 0, sizeof(b));
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < T; i++)
    {
      int tx, ty, tz;
      scanf("%d%d%d", &tx, &ty, &tz);
      int arr[3] = {tx, ty, tz};
      
      sort(arr, arr + 3);
      
      // permutation
      b[size].x = arr[0], b[size].y = arr[1], b[size++].z = arr[2];
      b[size].x = arr[0], b[size].y = arr[2], b[size++].z = arr[1];
      b[size].x = arr[1], b[size].y = arr[2], b[size++].z = arr[0];
      
      sort(b, b+size, cmp);
    }
    
    for (int i = 0; i < size; i++)
    {
      dp[i] = b[i].z;
      for (int j = i - 1; j >= 0; j--)
      {
        if (b[i].x < b[j].x && b[i].y < b[j].y) {
          dp[i] = max(dp[j] + b[i].z, dp[i]);
        }
      }
      ans = max(ans, dp[i]);
    }
    printf("Case %d: maximum height = %d\n", ++kases, ans);
  }
  return 0;
}
