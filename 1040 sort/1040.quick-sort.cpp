/**
* HDU1040 ��������д�� 
*/
#include <cstdio> 
#include <cstring>
// #include <algorithm>
// using namespace std;
const int MAXN = 1e5 + 10;
int t, n;
int data[MAXN];

/**
* mysort() : �����ڿ�����˼��ʵ�ֵĿ��������㷨 
* @param int* data ����������� 
* @param int left ���
* @param int right �յ� 
*/ 
void mysort(int data[], int left, int right)
{
  if (left >= right) {
    return;
  }
  int i = left, 
    j = right, 
    ref = data[i];      // �ѵ�һ������Ϊ flag
  while (i < j) 
  {
    // �Ӻ���ǰ�ҵ���һ���Ȳο���С�� 
    while (i < j && data[j] >= ref)
    {
      j--;
    }
    // �滻 data[i] Ϊ data[j] 
    data[i] = data[j]; 
    // ��ǰ�����ҵ���һ���Ȳο������ 
    while (i < j && data[i] <= ref)
    {
      i++;
    }
    // �滻 data[j] Ϊ data[i] 
    data[j] = data[i];
  }
  // Ȼ����ڳ����Ĳο������ȥ 
  data[i] = ref;
 
  // �ٶ����ڵ� i �����߽���������̣�ע������鲢����� mid 
  mysort(data, left, i - 1);
  mysort(data, i + 1, right);
}

/**
 * ����д��Ҳ�ǿ��Եģ�
 */
/*
void mysort(int* data, int left, int right)
{
  int ref = data[(left + right) >> 1],    // ���м������Ϊ������
    i = left,
    j = right;
  // ���������һ���� i < j
  while (i < j)
  {
    while (data[i] < ref)
      ++i;
    while (data[j] > ref)
      --j;
    // ע������������� i <= j, �������ͽ���������
    if (i <= j) {
      data[i] = data[i] + data[j];
      data[j] = data[i] - data[j];
      data[i] = data[i] - data[j];
    }
    if (i < right)
      mysort(data, i, right);
    if (left < j)
      mysort(data, left, j);
  }
}
 */

int main()
{
  scanf("%d", &t);
  while (t--) 
  {
    memset(data, 0, sizeof data);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &data[i]);
    }
    // sort(data, data + n);
    mysort(data, 0, n-1);
    
    for (int i = 0; i < n; i++)
    {
      if (i == n - 1) {
        printf("%d", data[i]);
      } else {
        printf("%d ", data[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
