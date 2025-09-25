#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;

bool isHamming(string a, string b) {
    int cnt = 0;
    for(int i = 0; i < k; i++) { 
        if(a[i] != b[i]) cnt++;
    }

    return cnt == 1 ? true : false;
}

void solve(int start, int end, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1);
    vector<int> trace(n + 1);
    queue<int> q;

    visited[start] = true;
    trace[start] = -1;
    q.push(start);

    bool check = false;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == end) {
            check = true;
            break;
        }

        for(int next : adj[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                trace[next] = cur;
                q.push(next);
            }
        }
    }

    if(!check) {
        cout << -1 << '\n';
        return;
    }
    
    vector<int> ans;
    ans.push_back(end);
    int cur = end;

    while(cur != -1) {
        ans.push_back(trace[cur]);
        cur = trace[cur];
    }

    for(int i = ans.size() - 2; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<string> v(n + 1);
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> v[i];
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(isHamming(v[i], v[j])) adj[i].push_back(j); 
        }
    }

    int a, b;
    cin >> a >> b;
    solve(a, b, adj);

    return 0;
}