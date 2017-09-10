#include <bits/stdc++.h> 

using namespace std;

const int MAXN = 15;
const int MAXS = 1 << MAXN;
const int INF = 1e9 + 7;

struct Lesson {
  int deadline;
  int need;
  char name[105];
};

struct State {
  int day;
  int doing;
  int score;
  int previous;
};

Lesson les[MAXN];
State dp[MAXS];

int cases;
int n, l;

int main()
{
  scanf("%d", &cases);
  while (cases--)
  {
    memset(dp, 0, sizeof(dp));
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
      cin >> les[i].name >> les[i].deadline >> les[i].need;
    }
    
    int terminal = 1 << n;
    
    // state-compressing
    for (int i = 1; i < terminal; i++)
    {
      dp[i].score = INF;
      for (int j = n - 1; j >= 0; j--)
      {
        int current = 1 << j;
        if (i & current)
        {
          int prev = i - current;     // previous state
          int score = dp[prev].day + les[j].need - les[j].deadline;
          if (score < 0)
            score = 0;
            
          int newState = score + dp[prev].score;
          if (newState < dp[i].score)
          {
            dp[i].score = newState;
            dp[i].day = dp[prev].day + les[j].need;
            dp[i].previous = prev;
            dp[i].doing = j;
          }
        }
      } // for j = n-1 => 0
    } // for i = 1 => terminal
    
    printf("%d\n", dp[terminal - 1].score);
    
    // print solutions
    stack<int> solutions;
    int cur = terminal - 1;
    while (cur != 0)
    {
      solutions.push(dp[cur].doing);
      cur = dp[cur].previous;
    }
    
    while (!solutions.empty())
    {
      printf("%s\n", les[solutions.top()].name);
      solutions.pop();
    }
  }
  
  return 0;
}
