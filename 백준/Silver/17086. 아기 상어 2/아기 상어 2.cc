#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int map[51][51];
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

int bfs(pii start)
{
    queue<pair<pii, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));

    q.push({start, 0});
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        pii cur = q.front().first;
        int dis = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny])
                continue;

            if (map[nx][ny] == 1)
                return dis + 1;

            q.push({{nx, ny}, dis + 1});
            visited[nx][ny] = true;
        }
    }

    return (int)1e10;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                ans = max(ans, bfs({i, j}));
            }
        }
    }

    cout << ans << "\n";
    return 0;
}