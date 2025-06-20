#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, e;
vector<pii> adj[801];

int dijkstra(int start, int end) {
  vector<int> dist(801, 1e9);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  
  dist[start] = 0;
  pq.push({0, start});
  
  while(!pq.empty()) {
    int cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    
    for(pii edge : adj[cur]) {
      int next = edge.first;
      int nextCost = cost + edge.second;
      if(nextCost < dist[next]) {
        dist[next] = nextCost;
        pq.push({nextCost, next});
      }
    }
  }
  
  return dist[end] == 1e9 ? -1 : dist[end];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> e;
  for(int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  
  int v1, v2, totalA, totalB;
  cin >> v1 >> v2;
  
  int path1 = dijkstra(1, v1);
  int path2 = dijkstra(v1, v2);
  int path3 = dijkstra(v2, n);
  if(path1 == -1 || path2 == -1 || path3 == -1) totalA = -1;
  else totalA = path1 + path2 + path3;
  
  int path4 = dijkstra(1, v2);
  int path5 = dijkstra(v2, v1);
  int path6 = dijkstra(v1, n);
  if(path4 == -1 || path5 == -1 || path6 == -1) totalB = -1;
  else totalB = path4 + path5 + path6;
  
  int ans;
  if(totalA == -1 && totalB == -1) ans = -1;
  else if(totalA == -1) ans = totalB;
  else if(totalB == -1) ans = totalA;
  else ans = min(totalA, totalB);
  
  cout << ans << '\n';
  
  return 0;
}