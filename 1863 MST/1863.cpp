/**
* HDU1863 畅通工程系列 
* 相比较 HDU1233 的区别就在于这题的话不一定使得整个村子都连通，所以要判断一下给定的道路是否使之连通 
* 具体做法就是跑 kruskal 合并两个点的时候对当前加入的边数 ++，如果最终边数 < 村庄数 -1，那就是不能连通输出 ? 
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
