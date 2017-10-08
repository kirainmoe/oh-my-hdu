/**
 * HDU1243 LCS变形
 * 带有权值的 LCS... 注意一下输入数据和 DP 时候数组下标的问题，dp 方程的下标是从 1 开始，所以记得 -1.
 * dp[i][j] = dp[i-1][j-1] + val[s1[i]] (s1[i] == s2[j]), max(dp[i-1][j], dp[i][j-1]) (s1[i] != s2[j])
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2333;

int n;
char types[2333];
int score[2333];
int dp[MAXN][MAXN];

char s1[MAXN], s2[MAXN];

void init()
{
  memset(types, 0, sizeof types);
  memset(dp, 0, sizeof dp);
  memset(score, 0, sizeof score);
}

void debug_trace()
{
  printf("Debug Mode:\n");
  printf("n: %d\n", n);
  printf("sequence 1: %s\n", types);
  for (int i = 0; i < n; i++)
    printf("Type %c: value %d\n", types[i], score[(int)types[i]]);
  printf("Gun sequence: %s\n", s1);
  printf("Terrior sequence: %s\n", s2);
  printf("End debug.\n");
}

int main()
{
  while (scanf("%d", &n) != EOF && n != 0)
  {
    scanf("%s", types);
    for (int i = 0; i < n; i++)
    {
      int tmp = 0;
      scanf("%d", &tmp);
      score[(int)types[i]] = tmp;
    }

    scanf("%s", s1);
    scanf("%s", s2);

    // debug_trace();

    // start dp
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i <= l1; i++)
      dp[i][0] = 0;
    for (int j = 0; j <= l2; j++)
      dp[0][j] = 0;

    for (int i = 1; i <= l1; i++)
    {
      for (int j = 1; j <= l2; j++)
      {
        if (s1[i-1] == s2[j-1]) {
          dp[i][j] = dp[i-1][j-1] + score[(int)s1[i-1]];
        } else {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      } // for j
    } // for i
    printf("%d\n", dp[l1][l2]);
  }
  return 0;
}
