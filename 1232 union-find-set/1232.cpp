/**
* HDU1232 畅通工程系列 
* 裸的并查集 orz 
*/
#include <bits/stdc++.h> 

const int MAXN = 1e3 + 10;
int p[MAXN];
int n, m;
int cnt = 0;

void init()
{
  cnt = 0;
  for (int i = 0; i < MAXN; i++)
  {
    p[i] = i;
  }
}

int find(int x)
{
  return x == p[x] ? x : p[x] = find(p[x]);
}

void unions(int x, int y)
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
    cnt++;
  }
}

int main()
{
  while (scanf("%d", &n) != EOF && n != 0)
  {
    init(); 
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
      int x, y;
      scanf("%d%d", &x, &y);
      unions(x, y);
    }
    printf("%d\n", (n - 1 - cnt));
  }
  return 0;
}
