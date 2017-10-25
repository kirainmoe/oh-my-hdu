#include <cstdio> 
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 19260817;
const int MAXN = 1e3 + 10;

struct Edge {
  int v, w;
  Edge (int tv, int tw)
  {
    v = tv, w= tw;
  }
};

int t, s, d;
vector<Edge> e[MAXN];
bool vis[MAXN];
int dist[MAXN];
int wish[MAXN], linked[MAXN];
int ans = INF;

void init()
{
  ans = INF;
  for (int i = 0; i < MAXN; i++)
  {
    e[i].clear();
  }
  memset(wish, 0, sizeof wish);
  memset(linked, 0, sizeof linked);
}

void spfa(int s)
{
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < MAXN; i++)
    dist[i] = INF;
  
  queue<int> Q;
  dist[s] = 0;
  vis[s] = 1;
  Q.push(s);
  
  while (!Q.empty())
  {
    int cur = Q.front();
    Q.pop();
    vis[cur] = 0;
    
    for (unsigned int i = 0; i < e[cur].size(); i++)
    {
      int v = e[cur][i].v, w = e[cur][i].w;
      if (dist[v] > dist[cur] + w) {
        dist[v] = dist[cur] + w;
        vis[v] = 1;
        Q.push(v);
      }
    }
  }
}

int main()
{
  while (scanf("%d%d%d", &t, &s, &d) != EOF)
  {
    init();
    
    for (int i = 0; i < t; i++)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      
      // ȥ�ر� & �ӱ� 
      bool flag1 = 0, flag2 = 0;
      for (unsigned int i = 0; i < e[u].size(); i++)
      {
        // �жϴ� u �� v �ı��Ƿ��Ѿ�������Ȩֵ�Ƿ����С 
        if (e[u][i].v == v && e[u][i].w > w) {
          e[u][i].w = w, flag1 = 1;
        }
      }
      // ����ͼӱߡ����������ƺ����� u �� v �бߵ���Ȩֵ�Ƚ�С��ʱ�򻹻��ر�
      // �������ⲻ����Ϊ��Ӱ������x �Ӹ��жϾͺ��� 
      if (!flag1) {
        e[u].push_back(Edge(v, w));
      }
      
      for (unsigned int i = 0; i < e[v].size(); i++) 
      {
        if (e[v][i].v == u && e[v][i].w > w) {
          e[v][i].w = w, flag2 = 1;
        }
      }
      if (!flag2) {
        e[v].push_back(Edge(u, w));
      }
    }
    
    for (int i = 0; i < s; i++)
    {
      scanf("%d", &linked[i]);
    }
    
    for (int i = 0; i < d; i++)
    {
      scanf("%d", &wish[i]);
    }
    
    for (int i = 0; i < s; i++)
    {
      int u = linked[i];
      spfa(u);
      for (int j = 0; j < d; j++)
      {
        int v = wish[j];
        ans = min(ans, dist[v]);
      }
    }
    
    printf("%d\n", ans);
  }
  return 0;
}
