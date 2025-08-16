#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

vector<vector<int>> adj;
vector<int> visited;

void bfs(int start) {
    queue<pii> q;
    q.push({start, 1});
    visited[start] = 1;

    while(!q.empty()) {
        int cur = q.front().first;
        int team = q.front().second;
        q.pop();

        for(int next : adj[cur]) {
            if(visited[next]) continue;

            int t = team == 1 ? 2 : 1;
            q.push({next, t});
            visited[next] = t;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;

        for(int j = 0; j < cnt; j++) {
            int p;
            cin >> p;
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            bfs(i);
        }
    }

    vector<int> blue;
    vector<int> white;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 1) blue.push_back(i);
        else if(visited[i] == 2) white.push_back(i);
    }

    cout << blue.size() << '\n';
    for(int num : blue) {
        cout << num << ' ';
    }
    cout << '\n';
    cout << white.size() << '\n';
    for(int num : white) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}