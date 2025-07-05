#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9
typedef pair<int, int> pii;

int n, m;
vector<vector<pii>> adj;

void dijkstra(int start, int end) {
    vector<int> dist(n + 1, INF);
    vector<int> trace(n + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(auto [next, nextCost] : adj[cur]) {
            if(dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                trace[next] = cur;
                pq.push({cost + nextCost, next});
            } 
        }
    }

    cout << dist[end] << '\n';

    vector<int> tmp;
    int idx = end;
    while(true) {
        tmp.push_back(idx);
        if(idx == start) break;
        idx = trace[idx];
    }
    
    cout << tmp.size() << '\n';
    for(int i = tmp.size() - 1; i >= 0; i--) {
        cout << tmp[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    adj.resize(n + 1);
    for(int i  = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    int start, end;
    cin >> start >> end;
    dijkstra(start, end);

    return 0;
}