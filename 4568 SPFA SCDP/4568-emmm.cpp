#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MAXN = 205;
const int MAXT = 14;

struct Point {
  int x, y;
};
Point target[MAXT];

int k, cases, row, col;
int dp[1 << MAXT][MAXT];
int dist[MAXN][MAXN];
int toEdge[MAXT], toEach[MAXT][MAXT];
int dir[2][4] = {
  { 0, 0, 1, -1 },
  { 1, -1, 0, 0 }
};
bool vis[MAXN][MAXN];

vector<int> G[MAXN];

void SPFA(int s)
{
  // init
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++)
      dist[i][j] = INF;

  queue<Point> Q;

  Point start;
  start.x = target[s].x, start.y = target[s].y;
  vis[start.x][start.y] = 1;
  dist[start.x][start.y] = 0;
  Q.push(start);

  while (!Q.empty())
  {
    Point cur = Q.front();
    Q.pop();
    vis[cur.x][cur.y] = 0;

    // is border
    if (cur.x == 0 || cur.y == 0 || cur.x == row - 1 || cur.y == col - 1) {
      toEdge[s] = min(toEdge[s], dist[cur.x][cur.y]);
    }

    // extending
    for (int i = 0; i < 4; i++)
    {
      Point next;
      next.x = cur.x + dir[0][i], next.y = cur.y + dir[1][i];
      if (next.x >= 0 && next.y >= 0 && next.x < row && next.y < col && G[next.x][next.y] != -1) {
        if (dist[next.x][next.y] > dist[cur.x][cur.y] + G[next.x][next.y]) {
          dist[next.x][next.y] = dist[cur.x][cur.y] + G[next.x][next.y];
          if (!vis[next.x][next.y]) {
            Q.push(next);
            vis[next.x][next.y] = 1;
          }
        }
      }
    } // for i
  } // while
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

    // get distance
    for (int i = 0; i < k; i++)
    {
      SPFA(i);
      for (int j = 0; j < k; j++)
      {
        if (i == j) {
          toEach[i][j] = 0;
          continue;
        }
        int jx = target[j].x, jy = target[j].y;
        toEach[i][j] = min(toEach[i][j], dist[jx][jy]);
      }
      // come in + current value
      dp[1 << i][i] = toEdge[i] + G[target[i].x][target[i].y];
    }

    // solve
    // enum state
    for (int state = 0; state < (1 << k); state++)
    {
      // enum current
      for (int i = 0; i < k; i++)
      {
        if ((state & (1 << i)) == 0) {
          continue;
        }

        // it is accepted even if I commited it.
        // current point is unvisible
        if (dp[state][i] == INF) {
          continue;
        }
       
        // enum next
        for (int j = 0; j < k; j++)
        {
          if ((state & (1 << j)) == 1) {
            continue;
          }
          int next = (state | (1 << j));
          dp[next][j] = min(dp[next][j], dp[state][i] + toEach[i][j]);
        } // for j
      } // for i
    } // for state

    int ans = INF;
    for (int i = 0; i < k; i++)
    {
      // go out
      ans = min(dp[(1 << k) - 1][i] + toEdge[i], ans);
    }
    printf("%d\n", ans);
  }
  return 0;
}