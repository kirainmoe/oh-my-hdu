 #include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 105;

struct Edge {
  int v, w;
  Edge(int tv, int tw)
  {
    v = tv, w = tw;
  }
};
int n, m;
int ans = 0;
int dist[MAXN];
bool vis[MAXN];
vector<Edge> e[MAXN];

void init()
{
  ans = 0;          // ��ʼ���� 
  
  memset(vis, 0, sizeof vis);
  
  for (int i = 0; i < MAXN; i++)
  {
    dist[i] = INF;
    e[i].clear();
  }
}

int main()
{
  // n Ϊ�������� m Ϊ������ 
  while (scanf("%d%d", &m, &n) != EOF && m != 0)
  {
    init();
    for (int i = 0; i < m; i++)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      
      e[u].push_back(Edge(v, w));
      e[v].push_back(Edge(u, w));
    }
    
    /* Prim */
    bool flag = true;               // ��� flag = false��˵���޷���ͨ����ͼ 
    dist[1] = 0, vis[1] = 1;        // ��Ϊ��Ŀ�ı�Ŵ� 1 ��ʼ�����԰� 1 ��Ϊ��� 
    // �����������бߣ����� dist[v] = w
    for (unsigned int i = 0; i < e[1].size(); i++)
    {
      int v = e[1][i].v, w = e[1][i].w;
      dist[v] = w;
    }
    /*
    ע������ı߽磬i = 1(���) -> n(���һ����)�����һ�����ǲ����ʵ�
    ��Ϊ������ʵ����һ����ʱͼ�Ѿ���ͨ��vis[x] = 1 һ����������ô flag �ᱻ����Ϊ false 
    */
    for (int i = 1; i < n; i++)
    {
      int cur, w = INF;         // cur �ǵ�ǰ���ҵ�����һ��������С�ĵ㣬w ����С���� 
      // �� dijkstra ��Щ����ͬ��֮�� 
      for (int j = 1; j <= n; j++)
      {
        if (!vis[j] && dist[j] < w) {
          cur = j, w = dist[j];
        }
      }
      // ����Ҳ������������ĵ㣬˵��ͼ�޷���ͨ 
      if (w == INF) {
        flag = false;
        break;
      }
      
      ans += w;
      vis[cur] = 1;     // �����һ�����ѷ���
      // ����ѡ���ĵ㣬�����������г��ߣ������ɳڲ��� 
      for (unsigned i = 0; i < e[cur].size(); i++)
      {
        int v = e[cur][i].v, w = e[cur][i].w;
        if (!vis[v] && dist[v] > w) {
          dist[v] = w;
        }
      }
    } /* end prim */
    
    if (!flag) {
      printf("?\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}

