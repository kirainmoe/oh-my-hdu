/**
* HDU1166 敌兵布阵 
* 终于 A 掉了人生中第一道线段树模板题 QAQ... 
* 线段树数组要开 4 倍！4 倍！4 倍！不然会 RE 得很难看的 QAQ 
*/

#include <bits/stdc++.h> 
const int MAXN = 50010;

int n;
int kases, tmp;

struct SegTree
{
  int sum[MAXN << 2];
  
  void pushUp(int root) 
  {
    sum[root] = sum[root * 2] + sum[root * 2 + 1];
  }
  
  void build(int left, int right, int root)
  {
    if (left == right)
    {
      scanf("%d", &sum[root]);
      return;
    }
    int middle = (left + right) / 2;
    build(left, middle, root * 2);
    build(middle + 1, right, root * 2 + 1); 
    
    pushUp(root);
  }
  
  void update(int left, int right, int root, int pos, int addVal)
  {
    if (left == right)
    {
      sum[root] += addVal;
      return;
    }
    int middle = (left + right) / 2;
    
    if (pos <= middle)
    {
      update(left, middle, root * 2, pos, addVal);
    }
    else
    {
      update(middle + 1, right, root * 2 + 1, pos, addVal);
    }
    
    pushUp(root);
  }
  
  int query(int from, int to, int left, int right, int root)
  {
    if (from <= left && right <= to)
    {
      return sum[root];
    }
    
    int middle = (left + right) / 2;
    
    int res = 0;
    if (to <= middle)
    {
      res += query(from, to, left, middle, root * 2);
    }
    else if (from > middle)
    {
      res += query(from, to, middle + 1, right, root * 2 + 1);
    }
    else
    {
      res += query(from, to, left, middle, root * 2) + query(from, to, middle + 1, right, root * 2 + 1);
    }
    
    return res;
  }
  
  void init()
  {
    for (int i = 0; i < MAXN; i++)
    {
      sum[i] = 0;
    }
  }
};

SegTree tree;

int main()
{
  freopen("1166.in", "r", stdin);
  freopen("1166.std.out", "w", stdout);
  scanf("%d", &kases);
  
  while (kases--) 
  {
    tmp++;
    printf("Case %d:\n", tmp);
    
    scanf("%d", &n);
    
    tree.init();
    tree.build(1, n, 1);
    
    char commands[20];
    while (scanf("%s", commands) != EOF && commands[0] != 'E')
    {
      if (commands[0] == 'Q')
      {
        int x, y;
        scanf("%d%d", &x, &y);
        
        int res = tree.query(x, y, 1, n, 1);
        printf("%d\n", res);
      }
      
      if (commands[0] == 'A')
      {
        int x, y;
        scanf("%d%d", &x, &y);
        tree.update(1, n, 1, x, y);
      }
      
      if (commands[0] == 'S')
      {
        int x, y;
        scanf("%d%d", &x, &y);
        tree.update(1, n, 1, x, -y);
      }
    }
  }
  
  fclose(stdin);
  fclose(stdout);
  
  return 0;
}
