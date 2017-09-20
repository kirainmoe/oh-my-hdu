/**
 * HDU1080 另类有权值的 LCS
 * 总共 WA 了 6 遍才过 QAQ...
 * 题解以后再补（
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 210;

int cases;
int s1[MAXN], s2[MAXN];
int len1, len2;
int dp[MAXN][MAXN];
int maps[5][5] = {
  { 5, -1, -2, -1, -3 },
  { -1, 5, -3, -2, -4 },
  { -2, -3, 5, -2, -2 },
  { -1, -2, -2, 5, -1 },
  { -3, -4, -2, -1, 0 }
};
char raw[MAXN];

int trans(char i)
{
  if (i == 'A')
    return 0;
  if (i == 'C')
    return 1;
  if (i == 'G')
    return 2;
  if (i == 'T')
    return 3;
  return 4;
}

int main()
{
  scanf("%d", &cases);
  while (cases--)
  {
    memset(s1, 0, sizeof s1);
    memset(s2, 0, sizeof s2);
    memset(dp, 0, sizeof dp);
    memset(raw, 0, sizeof raw);

    scanf("%d", &len1);
    scanf("%s", raw);
    for (int i = 0; i < len1; i++)
    {
      s1[i+1] = trans(raw[i]);
    }
    memset(raw, 0, sizeof raw);
    scanf("%d", &len2);
    scanf("%s", raw);
    for (int i = 0; i < len2; i++)
    {
      s2[i+1] = trans(raw[i]);
    }

    // init
    for (int i = 1; i <= len1; i++)
      dp[i][0] = dp[i-1][0] + maps[s1[i]][4];
    for (int i = 1; i <= len2; i++)
      dp[0][i] = dp[0][i-1] + maps[s2[i]][4];

    // dp
    for (int i = 1; i <= len1; i++)
    {
      for (int j = 1; j <= len2; j++)
      {
        dp[i][j] = max(
          dp[i-1][j] + maps[s1[i]][4],
          dp[i][j-1] + maps[4][s2[j]]
        );
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + maps[s1[i]][s2[j]]);
      }
    }

    printf("%d\n", dp[len1][len2]);
  }
  return 0;
}