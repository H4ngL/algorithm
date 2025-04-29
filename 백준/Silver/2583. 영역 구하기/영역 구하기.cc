#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int m, n, k;
int paper[101][101];
bool visited[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void fillPaper(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < x2; i++)
    {
        for (int j = y1; j < y2; j++)
        {
            paper[i][j]++;
        }
    }
}

int bfs(pii start)
{
    int ret = 0;

    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    ret++;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (paper[nx][ny] == 0 && !visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                ret++;
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        fillPaper(x1, y1, x2, y2);
    }

    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (paper[i][j] == 0 && !visited[i][j])
            {
                ans.push_back(bfs({i, j}));
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int size : ans)
        cout << size << " ";

    return 0;
}