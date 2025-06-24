#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define INF 1e9

int n, m;
vector<pii> adj[50001];

int dijkstra(int start, int end) {
  vector<int> cost(50001, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  cost[start] = 0;
  pq.push({0, start});
  
  while(!pq.empty()) {
    int curCost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    
    for(auto [next, nextCost] : adj[cur]) {
      if(cost[next] > curCost + nextCost) {
        cost[next] = curCost + nextCost;
        pq.push({curCost + nextCost, next});
      }
    }
  }
  
  return cost[end];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
    }
    
    cout << dijkstra(1, n) << '\n';
    
    return 0;
}