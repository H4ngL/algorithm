#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define INF 1e9

int n, m, r;
vector<int> items;
vector<pii> adj[101];

int dijkstra(int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur]) continue;

        for (auto [next, length] : adj[cur]) {
            if (dist[next] > cost + length) {
                dist[next] = cost + length;
                pq.push({dist[next], next});
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= m) cnt += items[i];
    }

    return cnt;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m >> r;
  items.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> items[i];
  }
  
  for(int  i = 0; i < r; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    adj[a].push_back({b, l});
    adj[b].push_back({a, l});
  }
  
  int maxItems = 0;
  for(int i = 1; i <= n; i++) {
    maxItems = max(maxItems, dijkstra(i));
  }
  cout << maxItems << '\n';
  
  return 0;
}