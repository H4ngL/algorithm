#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define INF 1e9

int n, m;
vector<pii> adj[5001];

int dijkstra(int start, int end) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> dist(5001, INF);
  
  dist[start] = 0;
  pq.push({0, start});
  
  while(!pq.empty()) {
    int cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    
    for(auto [next, nextCost] : adj[cur]) {
      if(dist[next] > nextCost + cost) {
        dist[next] = nextCost + cost;
        pq.push({nextCost + cost, next});
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
    int a, b, c;
    cin >> a >> b >> c; 
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  
  int s, t;
  cin >> s >> t;
  cout << dijkstra(s, t) << '\n';
  
  return 0;
}