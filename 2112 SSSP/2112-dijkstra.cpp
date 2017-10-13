/**
* ACM HDU P2112 HDU Today
* Dijkstra / SPFA
* June 6th, 2017, kirainmoe
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
const int inf = 1e9;

int d[maxn];

map<string, int> stations;
vector<pair<int, int> > edges[maxn];
string start, final;

void initialize()
{
  for (int i = 0; i < maxn; i++)
  {
    edges[i].clear();
    d[i] = inf;
  }
}

int main()
{
  int countStation;
  while (scanf("%d", &countStation) != EOF)
  {
    if (countStation == -1) {
      break;
    }
    
    initialize();
    // read in
    cin >> start >> final;
    for (int i = 0; i < countStation; i++)
    {
      string u, v;
      int w;
      cin >> u >> v >> w;
      
      if (stations.count(u) <= 0) {
        stations[u] = stations.size();
      }
      if (stations.count(v) <= 0) {
        stations[v]  = stations.size();
      }
      
      int begin, end;
      begin = stations[u], end = stations[v];
      
      edges[begin].push_back(make_pair(end, w));
      edges[end].push_back(make_pair(begin, w));
    }
    
    int startNumber = stations[start],
        finalNumber = stations[final];
    
    if (startNumber == finalNumber) {
      printf("%d\n", 0);
      continue;
    }
    
    priority_queue<pair<int, int> > Q;
    d[startNumber] = 0;
    
    Q.push(make_pair(-d[startNumber], startNumber));

    while (!Q.empty())
    {
      int cur = Q.top().second;
      Q.pop();
      
      for (int i = 0; i < edges[cur].size(); i++)
      {
        int tar = edges[cur][i].first,
            dis = edges[cur][i].second;
        if (d[tar] > d[cur] + dis) {
          d[tar] = d[cur] + dis;
          Q.push(make_pair(-d[tar], tar));
        } // if
      } // for
    } // while
    if (d[finalNumber] == inf) {
      printf("%d\n", -1);
    } else {
      printf("%d\n", d[finalNumber]);
    }
  }
  return 0;
}
