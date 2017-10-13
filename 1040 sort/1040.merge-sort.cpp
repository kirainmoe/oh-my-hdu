/**
* HDU1040 merge sort version
* �鲢����ģ���� 
*/
#include <cstdio> 
#include <cstring>

const int MAXN = 1e4 + 10;
int t, n;
int ans = 0;        // ���Ҫ�ù鲢����������� 
int data[MAXN],     // ԭʼ���� 
  tmp[MAXN],        // �鲢���� 
  res[MAXN];        // ������ 

void init()
{
  n = 0;
  ans = 0;
  memset(data, 0, sizeof data);
  memset(tmp, 0, sizeof tmp);
  memset(res, 0, sizeof res);
}

/**
* �ϲ�һ������ 
* @param int left ���
* @param int mid �м�λ��
* @param int right �յ� 
*/ 
void merge(int left, int mid, int right)
{
  int i = left, j = mid + 1, k = left;    // ���� i, j, k �±���� 
  // ��Ŀ�겿���ٷ�Ϊ���������� 
  while (i <= mid && j <= right)
  {
    // ��ߵ������ұߵ�����
    if (res[i] > res[j]) {
      tmp[k++] = res[j++];
      ans += mid - i + 1;                  // ��������� 
    } else {
      tmp[k++] = res[i++];
    }
  }
  // �ٰ��������ߵ�ֵ����һ��ѭ��û�������Ĳ�������ȥ 
  while (i <= mid)
  {
    tmp[k++] = res[i++];
  }
  while (j <= right)
  {
    tmp[k++] = res[j++];
  }
  // ���ϲ��� res �����м�Ϊ��� 
  for (int i = left; i <= right; i++)
  {
    res[i] = tmp[i];
  }
}

/**
* �鲢���򣺻��ֹ��� 
* @param int start �������
* @param int end �����յ� 
*/ 
void merge_sort(int start, int end)
{
  int middle = (start + end) / 2;     // �����ֵ��е�
  // �����ǰ�����䳤��Ϊ 1���������ٻ��� 
  if (start < end) {
    merge_sort(start, middle);
    merge_sort(middle + 1, end); 
    merge(start, middle, end);
  }
}

int main()
{
  scanf("%d", &t);
  
  while (t--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &data[i]);
      res[i] = data[i];       // ����ԭ���� 
    }
    
    merge_sort(0, n - 1);
    
    for (int i = 0; i < n; i++)
      if (i != n - 1) {
        printf("%d ", res[i]);
      } else {
        printf("%d", res[i]);
      }
    /* printf("\nInversion number: %d\n", ans);   // ����� */
    printf("\n");
  }
  
  return 0;
}
