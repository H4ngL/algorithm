#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define INF 1e9

void dijkstra(vector<vector<pii>> &adj, int n, int start) {
  vector<int> dist(n + 1, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  
  dist[start] = 0;
  pq.push({0, start});
  
  while(!pq.empty()) {
    int cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    
    for(auto [next, second] : adj[cur]) {
      if(dist[next] > cost + second) {
        dist[next] = cost + second;
        pq.push({cost + second, next});
      }
    }
  }
  
  int cnt = 0, time = 0;
  for(int i = 1; i <= n; i++) {
    if(dist[i] != INF) {
      cnt++;
      time = max(time, dist[i]);
    }
  }
  
  cout << cnt << ' ' << time << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
      int n, d, c;
      cin >> n >> d >> c;
      
      vector<vector<pii>> adj(n + 1);
      for(int i = 0; i < d; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        adj[b].push_back({a, s});
      }
      
      dijkstra(adj, n, c);
    }
    
    return 0;
}