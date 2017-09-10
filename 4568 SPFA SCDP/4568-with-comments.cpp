#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MAXN = 205;
const int MAXT = 14;

struct Point {
  int x, y;
};
Point target[MAXT];    // 宝藏坐标

int k, cases, row, col;

// dp[i][j] 表示当前已经过的宝藏点状态为 i, 并且终点为 j 时所花费的最小代价
// 那么有 DP 方程：dp[s|(1<<next)][next] = min(dp[s|(1<<next)][s], dp[s][cur] + toEach[cur][next]);
// 其中 next 是下一个目标状态点，cur 是当前状态的终点
int dp[1 << MAXT][MAXT];

// 用于 SPFA 计算每个宝藏点之间的距离
int dist[MAXN][MAXN];

// toEdge[i] 表示第 i 个宝藏点到边界的最小代价（不包括本身）
// toEach[i][j] 表示第 i 个宝藏点到第 j 个宝藏点的最小代价
int toEdge[MAXT], toEach[MAXT][MAXT];

// SPFA 拓展节点的方向
int dir[2][4] = {
  { 0, 0, 1, -1 },
  { 1, -1, 0, 0 }
};

// SPFA 记录点访问情况的数组
bool vis[MAXN][MAXN];

// 用不定长数组存储地图
vector<int> G[MAXN];

void SPFA(int s)
{
  // 初始化 SPFA
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++)
      dist[i][j] = INF;

  queue<Point> Q;

  Point start;
  start.x = target[s].x, start.y = target[s].y;
  vis[start.x][start.y] = 1;    // 标记起点为已访问
  dist[start.x][start.y] = 0;   // 起点到自身的最短路为 0
  Q.push(start);

  while (!Q.empty())
  {
    Point cur = Q.front();
    Q.pop();
    vis[cur.x][cur.y] = 0;    // 当前节点出队，标记为未访问

    // 到达边界，更新该点到边界的距离
    if (cur.x == 0 || cur.y == 0 || cur.x == row - 1 || cur.y == col - 1) {
      toEdge[s] = min(toEdge[s], dist[cur.x][cur.y]);
    }

    // 拓展节点
    for (int i = 0; i < 4; i++)
    {
      Point next;
      next.x = cur.x + dir[0][i], next.y = cur.y + dir[1][i];
      // 检验节点合法性以及是否可到达
      if (next.x >= 0 && next.y >= 0 && next.x < row && next.y < col && G[next.x][next.y] != -1) {
        // 松弛操作
        if (dist[next.x][next.y] > dist[cur.x][cur.y] + G[next.x][next.y]) {
          dist[next.x][next.y] = dist[cur.x][cur.y] + G[next.x][next.y];
          if (!vis[next.x][next.y]) {
            Q.push(next);
            vis[next.x][next.y] = 1;
          }
        }
      }
    } // end for i
  } // end while
}

void init()
{
  for (int i = 0; i < MAXN; i++)
    G[i].clear();

  for (int i = 0; i < (1 << MAXT); i++)
    for (int j = 0; j < MAXT; j++)
      dp[i][j] = INF;

  fill(toEdge, toEdge + MAXT, INF);

  for (int i = 0; i < MAXT; i++)
    for (int j = 0; j < MAXT; j++)
      toEach[i][j] = INF;
}

int main()
{
  scanf("%d", &cases);
  while (cases--)
  {
    init();
    scanf("%d%d", &row, &col);
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        int tmp;
        scanf("%d", &tmp);
        G[i].push_back(tmp);
      }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
      scanf("%d%d", &target[i].x, &target[i].y);
    }

    // 求每两个宝藏点之间的最短距离（最小代价）
    for (int i = 0; i < k; i++)
    {
      SPFA(i);
      for (int j = 0; j < k; j++)
      {
        // 自身到自身的代价为 0
        if (i == j) {
          toEach[i][j] = 0;
          continue;
        }
        int jx = target[j].x, jy = target[j].y;
        toEach[i][j] = min(toEach[i][j], dist[jx][jy]);
      }
      // dp[1 << i][i] 表示只访问了第 i 个点时的代价
      // 等于：从边界进来时的代价 + 自身的代价
      dp[1 << i][i] = toEdge[i] + G[target[i].x][target[i].y];
    }

    // solve
    // 枚举从 0 到 (1 << k) - 1 的每个状态
    for (int state = 0; state < (1 << k); state++)
    {
      // 枚举该状态当前的终点
      for (int i = 0; i < k; i++)
      {
        // 如果状态不包含当前点，则回溯
        if ((state & (1 << i)) == 0) {
          continue;
        }

        // 如果当前状态下到终点的距离还没有计算，则回溯？
        // 不太清楚是不是这样的，因为我注释掉这段代码仍然是 AC 的
        if (dp[state][i] == INF) {
          continue;
        }
       
        // 枚举在当前状态时，下一个目标是去哪一个宝藏点呢
        for (int j = 0; j < k; j++)
        {
          // 如果这个宝藏点已经访问过了，就回溯，因为每个点只能走一次
          if ((state & (1 << j)) == 1) {
            continue;
          }
          // 下一个状态
          int next = (state | (1 << j));
          
          // 下一个状态 next，终点为 j 的最小代价等于 这个代价 和 当前代价+(cur, next)两点间最短距离 的最小值
          dp[next][j] = min(dp[next][j], dp[state][i] + toEach[i][j]);
        } // for j
      } // for i
    } // for state

    // 输出答案
    int ans = INF;
    for (int i = 0; i < k; i++)
    {
      // 最终的最优答案是 min(dp[(1 << k) - 1][i]), i = 0...k
      // 因为 dp[i][j] 是以 j 为终点，但是我们最终需要从边界出去，所以还要加上终点到边界的最短距离
      ans = min(dp[(1 << k) - 1][i] + toEdge[i], ans);
    }
    printf("%d\n", ans);
  }
  return 0;
}