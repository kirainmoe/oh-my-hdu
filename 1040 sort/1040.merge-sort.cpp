/**
* HDU1040 merge sort version
* 归并排序模板题 
*/
#include <cstdio> 
#include <cstring>

const int MAXN = 1e4 + 10;
int t, n;
int ans = 0;        // 如果要用归并排序求逆序对 
int data[MAXN],     // 原始数据 
  tmp[MAXN],        // 归并数组 
  res[MAXN];        // 排序结果 

void init()
{
  n = 0;
  ans = 0;
  memset(data, 0, sizeof data);
  memset(tmp, 0, sizeof tmp);
  memset(res, 0, sizeof res);
}

/**
* 合并一个数组 
* @param int left 起点
* @param int mid 中间位置
* @param int right 终点 
*/ 
void merge(int left, int mid, int right)
{
  int i = left, j = mid + 1, k = left;    // 设置 i, j, k 下标起点 
  // 把目标部分再分为左右两部分 
  while (i <= mid && j <= right)
  {
    // 左边的数比右边的数大
    if (res[i] > res[j]) {
      tmp[k++] = res[j++];
      ans += mid - i + 1;                  // 更新逆序对 
    } else {
      tmp[k++] = res[i++];
    }
  }
  // 再把左右两边的值在上一个循环没有填充完的部分填充进去 
  while (i <= mid)
  {
    tmp[k++] = res[i++];
  }
  while (j <= right)
  {
    tmp[k++] = res[j++];
  }
  // 最后合并到 res 数组中即为结果 
  for (int i = left; i <= right; i++)
  {
    res[i] = tmp[i];
  }
}

/**
* 归并排序：划分过程 
* @param int start 划分起点
* @param int end 划分终点 
*/ 
void merge_sort(int start, int end)
{
  int middle = (start + end) / 2;     // 两部分的中点
  // 如果当前的区间长度为 1，则无需再划分 
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
      res[i] = data[i];       // 拷贝原数组 
    }
    
    merge_sort(0, n - 1);
    
    for (int i = 0; i < n; i++)
      if (i != n - 1) {
        printf("%d ", res[i]);
      } else {
        printf("%d", res[i]);
      }
    /* printf("\nInversion number: %d\n", ans);   // 逆序对 */
    printf("\n");
  }
  
  return 0;
}
