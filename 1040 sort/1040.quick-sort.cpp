/**
* HDU1040 快速排序写法 
*/
#include <cstdio> 
#include <cstring>
// #include <algorithm>
// using namespace std;
const int MAXN = 1e5 + 10;
int t, n;
int data[MAXN];

/**
* mysort() : 基于挖坑填数思想实现的快速排序算法 
* @param int* data 待排序的数组 
* @param int left 起点
* @param int right 终点 
*/ 
void mysort(int data[], int left, int right)
{
  if (left >= right) {
    return;
  }
  int i = left, 
    j = right, 
    ref = data[i];      // 把第一个数作为 flag
  while (i < j) 
  {
    // 从后往前找到第一个比参考数小的 
    while (i < j && data[j] >= ref)
    {
      j--;
    }
    // 替换 data[i] 为 data[j] 
    data[i] = data[j]; 
    // 从前往后找到第一个比参考数大的 
    while (i < j && data[i] <= ref)
    {
      i++;
    }
    // 替换 data[j] 为 data[i] 
    data[j] = data[i];
  }
  // 然后把挖出来的参考数填回去 
  data[i] = ref;
 
  // 再对现在的 i 的两边进行这个过程，注意区别归并排序的 mid 
  mysort(data, left, i - 1);
  mysort(data, i + 1, right);
}

/**
 * 以下写法也是可以的：
 */
/*
void mysort(int* data, int left, int right)
{
  int ref = data[(left + right) >> 1],    // 把中间的数作为参照数
    i = left,
    j = right;
  // 这里的条件一定是 i < j
  while (i < j)
  {
    while (data[i] < ref)
      ++i;
    while (data[j] > ref)
      --j;
    // 注意这里的条件是 i <= j, 如果满足就交换两个数
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
