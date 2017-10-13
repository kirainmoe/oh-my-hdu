/**
* HDU1233 ��С������ģ���� Kruskal ʵ�� 
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
struct Edge {
  int u, v, w;
};
int n, m;
int ans = 0, times = 0;
int p[MAXN];
Edge edges[MAXN * MAXN];

bool cmp(const Edge a, const Edge b)
{
  return a.w < b.w;
}

void init()
{
  ans = 0;          // ��ʼ���� 
  times = 0;        // ��ʼ���ϲ����� 
  
  memset(edges, 0, sizeof edges);
  
  // ��ʼ�����鼯 
  for (int i = 0; i < MAXN; i++)
  {
    p[i] = i;
  }
}

/* ���鼯������ */
int find(int x)
{
  return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
  // n Ϊ�������� m Ϊ������ 
  while (scanf("%d%d", &m, &n) != EOF && m != 0)
  {
    init();
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    // ���߰���Ȩֵ��С�������� 
    sort(edges, edges + m, cmp);
    
    for (int i = 0; i < m; i++)
    {
      int x = edges[i].u, y = edges[i].v;
      // ���鼯�ĺϲ�����
      // ��ѯ��ǰ�������յ����ڼ��� 
      int px = find(x),
        py = find(y);
      
      if (px == py) {
        continue;           // ��� px �� py ��һ�������У������κβ��� 
      } else {
        p[px] = py;         // �ϲ� 
        ans += edges[i].w;  // ���´� 
        times++;            // �ϲ�����+1 
      }
    }
    // û���ҵ���С������ 
    if (times != n-1) {
      printf("?\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
