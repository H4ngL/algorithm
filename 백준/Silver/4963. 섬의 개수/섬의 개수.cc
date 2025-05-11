#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int w, h;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};

void bfs(pii start, vector<vector<int>> &map, vector<vector<bool>> &visited)
{
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                continue;

            if (!visited[nx][ny] && map[nx][ny] == 1)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        vector<vector<int>> map(h, vector<int>(w));
        vector<vector<bool>> visited(h, vector<bool>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }

        int cnt = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!visited[i][j] && map[i][j] == 1)
                {
                    cnt++;
                    bfs({i, j}, map, visited);
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}