#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int student[5][5];
bool selected[25];
int ans;

bool bfs(vector<int> group)
{
    bool visited[25] = {false};
    queue<int> q;
    q.push(group[0]);
    visited[group[0]] = true;
    int count = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int cx = cur / 5;
        int cy = cur % 5;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int next = nx * 5 + ny;

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;

            if (!visited[next])
            {
                for (int k = 0; k < 7; k++)
                {
                    if (group[k] == next)
                    {
                        visited[next] = true;
                        q.push(next);
                        count++;
                        break;
                    }
                }
            }
        }
    }

    return count == 7;
}

void comb(int start, int cnt, vector<int> group, int sCnt)
{
    if (cnt == 7 && bfs(group))
    {
        if (sCnt >= 4)
            ans++;
        return;
    }

    for (int i = start; i < 25; i++)
    {
        if (selected[i])
            continue;

        selected[i] = true;
        group.push_back(i);
        int x = i / 5;
        int y = i % 5;
        comb(i + 1, cnt + 1, group, sCnt + student[x][y]);
        group.pop_back();
        selected[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 5; j++)
            student[i][j] = str[j] == 'Y' ? 0 : 1;
    }

    vector<int> group;
    comb(0, 0, group, 0);

    cout << ans << "\n";

    return 0;
}