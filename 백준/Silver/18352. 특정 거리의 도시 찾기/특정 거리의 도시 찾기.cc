#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, m, k, x;
vector<vector<int>> adj;

vector<int> bfs() {
    queue<pii> q;
    vector<bool> visited(n + 1);
    vector<int> v;

    q.push({x, 0});
    visited[x] = true;

    while(!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();

        if(dist == k) v.push_back(cur);

        for(int next : adj[cur]) {
            if(visited[next]) continue;
            q.push({next, dist + 1});
            visited[next] = true;
        }
    }

    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> x;

    adj.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> v = bfs();
    sort(v.begin(), v.end());

    if(v.empty()) cout << -1 <<'\n';
    else {
        for(int num : v) {
            cout << num << '\n';
        }
    }
    

    return 0;
}