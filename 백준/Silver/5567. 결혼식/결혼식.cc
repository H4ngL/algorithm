#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

vector<vector<int>> adj;
vector<bool> visited;

int bfs(int start) {
    queue<pii> q;
    q.push({start, 0});
    visited[start] = true;
    int cnt = 0;

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();

        for(int node : adj[cur.first]) {
            if(!visited[node] && cur.second < 2) {
                q.push({node, cur.second + 1});
                visited[node] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << bfs(1) << "\n";

    return 0;
}