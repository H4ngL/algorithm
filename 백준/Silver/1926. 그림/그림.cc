#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int arr[501][501];
bool visited[501][501];
int cnt, maxSize;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(pii start)
{
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    int size = 1;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (!visited[nx][ny] && arr[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                size++;
            }
        }
    }

    maxSize = max(maxSize, size);
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
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && arr[i][j])
            {
                bfs({i, j});
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    cout << maxSize << "\n";

    return 0;
}