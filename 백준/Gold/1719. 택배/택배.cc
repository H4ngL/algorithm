#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define INF 1e9

int n, m;
vector<vector<pii>> adj;

vector<int> dijkstra(int start) {
  vector<int> ret(n + 1);
  vector<pii> dist(n + 1, {INF, -1});
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  
  dist[start] = {0, -1};
  pq.push({0, start});
  
  while(!pq.empty()) {
    int cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    
    for(auto [next, time] : adj[cur]) {
      if(dist[next].first > cost + time) {
        dist[next].first = cost + time;
        if(cost == 0) dist[next].second = next;
        else dist[next].second = dist[cur].second;
        pq.push({cost + time, next});
      }
    }
  }
  
  for(int i = 1; i <= n; i++) {
    ret[i] = dist[i].second;
  }
  
  return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    adj.resize(n + 1);
    for(int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
    }
    
    for(int i = 1; i <= n; i++) {
      vector<int> v = dijkstra(i);
      for(int j = 1; j <= n; j++) {
        if(i == j)
          cout << '-' << ' ';
        else 
          cout << v[j] << ' ';
      }
      cout << '\n';
    }
    
    return 0;
}