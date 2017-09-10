/**
* HDU5489 LIS Solution 1:
* ��ΪҪ��������ɾ��һЩ��֮���� LIS��Ȼ���������ö��ɾ���������յ㣬Ȼ����յ��ұߵĵ�һ����Ϊ�����һ�� LIS 
* Ȼ���ٴ�����ߵ�ɾ���������һ�� **�������������յ��ұߵ�һ����** �� LIS 
* ������������ LIS ������ö�����֮ǰԤ������������ԣ� 
* ���������� LIS �����ø����ķ���������Ȼ�����������һֱ�� n �� l Ϊֹ��
*/
#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9 + 7;

int kases, tmp;
int n, l;
int a[MAXN], b[MAXN], dp[MAXN], LIS[MAXN];

int main()
{
  scanf("%d", &kases);
  
  while (kases--)
  {
    tmp++;
    scanf("%d%d", &n, &l);
    
    fill(dp, dp + MAXN, INF);
    
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      b[i] = -a[i];
    }
    
    // reverse LIS
    int pos = 0;
    fill(LIS, LIS + MAXN, INF);
    
    for (int i = l; i >= l; i--)
    {
      pos = lower_bound(LIS, LIS + n, b[i]) - LIS;
      LIS[pos] = b[i];
      dp[i] = pos + 1;
    }
    
    int ans = 0, maxlen = 0;
    fill(LIS, LIS + MAXN, INF);
    for (int i = l; i < n; i++)
    {
      pos = lower_bound(LIS, LIS + n, a[i]) - LIS;      // from left to right
      ans = max(ans, pos + 1 + dp[i] - 1);        // >=

      pos = lower_bound(LIS, LIS + n, a[i - l]) - LIS;    // update left LIS
      LIS[pos] = a[i-l];
      maxlen = max(maxlen, pos + 1);
    }
    ans = max(ans, maxlen);
    printf("Case #%d: %d\n", tmp, ans);
  }
  
  return 0;
}
