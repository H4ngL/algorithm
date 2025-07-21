#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9
typedef pair<int, int> pii;

int n;
vector<vector<int>> v;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dijkstra() {
    vector<vector<int>> cost(n, vector<int>(n, INF));
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    cost[0][0] = 0;
    pq.push({0, {0, 0}});

    while(!pq.empty()) {
        int cnt = pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();

        if(cost[cx][cy] < cnt) continue;

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            int cal = cnt + (v[nx][ny] ? 0 : 1);
            if(cost[nx][ny] > cal) {
                cost[nx][ny] = cal;
                pq.push({cal, {nx, ny}});
            }
        }
    }
    
    return cost[n - 1][n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < n; j++) {
            v[i][j] = str[j] - '0';
        }
    }

    cout << dijkstra() << '\n';
    return 0;
}