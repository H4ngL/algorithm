#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<vector<int>> maze;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dijkstra() {
    vector<vector<int>> wall(n, vector<int>(m, INF));
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    wall[0][0] = 0;
    pq.push({0, {0, 0}});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();

        if(wall[cx][cy] < cost) continue;

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;    

            if(wall[nx][ny] > cost + maze[nx][ny]) {
                wall[nx][ny] = cost + maze[nx][ny];
                pq.push({cost + maze[nx][ny], {nx, ny}});
            }
        }
    }

    return wall[n - 1][m - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    maze.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            maze[i][j] = str[j] - '0';
        }
    }

    cout << dijkstra() << '\n';
    return 0;
}