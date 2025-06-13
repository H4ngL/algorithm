#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9
typedef pair<int, int> pii;

int n, m;
vector<pii> graph[1001];

int dijkstra(int start, int end) {
  vector<int> dist(n + 1, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  
  dist[start] = 0;
  pq.push({0, start});
  
  while (!pq.empty()) {
    auto [cost, now] = pq.top();
    pq.pop();
    
    if (cost > dist[now]) continue;
    
    for (auto [next, time] : graph[now]) {
      if (dist[next] > cost + time) {
        dist[next] = cost + time;
        pq.push({dist[next], next});
      }
    }
  }
  
  return dist[end];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int s, e, c;
    cin >> s >> e >> c;
    graph[s].push_back({e, c});
  }
  
  int start, end;
  cin >> start >> end; 
  cout << dijkstra(start, end) << "\n";
    
  return 0;
}