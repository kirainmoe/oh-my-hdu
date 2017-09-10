#include <bits/stdc++.h> 
const int MAXN = 5 * 1e4 + 10;

struct SegTree
{
  int tree[MAXN << 2];
  
  void init()
  {
    for (int i = 0; i < (MAXN << 2); i++)
    {
      tree[i] = 0;
    }
  }
  
  void pushUp(int root)
  {
    tree[root] = tree[root * 2] + tree[root * 2 + 1];
  } // pushUp()
  
  void build(int left, int right, int root)
  {
    if (left == right)
    {
      scanf("%d", &tree[root]);
      return;
    }
    
    int middle = (left + right) / 2;
    build(left, middle, root * 2);
    build(middle + 1, right, root * 2 + 1);
    
    pushUp(root);
  } // build()
  
  void update(int left, int right, int root, int pos, int addVal)
  {
    if (left == right)
    {
      tree[root] += addVal;
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
  } // update()
  
  int query(int from, int to, int left, int right, int root)
  {
    if (from <= left && to >= right)
    {
      return tree[root];
    }
    
    int middle = (left + right) / 2, res = 0;
    if (to <= middle)
    {
      res += query(from, to, left, middle, root * 2);
    }
    else if (from > middle)
    {
      res += query(from, to, middle + 1, to, root * 2 + 1);
    }
    else
    {
      res += query(from, to, left, middle, root * 2) + query(from, to, middle + 1, right, root * 2 + 1);
    }
    
    return res;
  } // query()
};

SegTree T;
int kases, tmp = 0, n;

int main()
{
  scanf("%d", &kases);
  
  while (kases--)
  {
    printf("Case %d:\n", ++tmp);
    scanf("%d", &n);
    
    T.init();
    T.build(1, n, 1);
    
    char cmd[10];
    while (scanf("%s", cmd) != EOF && cmd[0] != 'E')
    {
      if (cmd[0] == 'Q')
      {
        int x, y;
        scanf("%d%d", &x, &y);
        int res = T.query(x, y, 1, n, 1);
        printf("%d\n", res);
      }
      
      if (cmd[0] == 'A' || cmd[0] == 'S')
      {
        int x, y;
        scanf("%d%d", &x, &y);
        cmd[0] == 'A' ? T.update(1, n, 1, x, y) : T.update(1, n, 1, x, -y);
      }
    }
  }
  
  return 0;
}
