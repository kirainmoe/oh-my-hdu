/**
* HDU1863 ��ͨ����ϵ�� 
* ��Ƚ� HDU1233 ���������������Ļ���һ��ʹ���������Ӷ���ͨ������Ҫ�ж�һ�¸����ĵ�·�Ƿ�ʹ֮��ͨ 
* �������������� kruskal �ϲ��������ʱ��Ե�ǰ����ı��� ++��������ձ��� < ��ׯ�� -1���Ǿ��ǲ�����ͨ��� ? 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

struct Edge {
  int u, v, w;
} edges[MAXN];

bool operator < (const Edge a, const Edge b)
{
  return a.w < b.w;
}

int cur = 0, cost = 0;
int n, m;
int p[MAXN];

void init()
{
  cur = 0, cost = 0;
  for (int i = 0; i < MAXN; i++)
  {
    edges[i].u = edges[i].v = edges[i].w = 0;
    p[i] = i;
  }
}

int find(int x)
{
  return x == p[x] ? x : p[x] = find(p[x]);
}

void unions(int x, int y, int w)
{
  int px = find(x),
      py = find(y);
  if (px == py)
  {
    return;
  }
  else
  {
    p[px] = py;
    cost += w;
    cur++;
  }
}

int main()
{
  while (scanf("%d%d", &m, &n) != EOF && m != 0)
  {
    init();
    for (int i = 0; i < m; i++)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      edges[i].u = u, edges[i].v = v, edges[i].w = w;
    }
    sort(edges, edges + m);
    
    for (int i = 0; i < m; i++)
    {
      unions(edges[i].u, edges[i].v, edges[i].w);
    }
    
    if (cur < n-1)
    {
      printf("?\n");
    }
    else
    {
      printf("%d\n", cost);
    }
  }
  return 0;
}
