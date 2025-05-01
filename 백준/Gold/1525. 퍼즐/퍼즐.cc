#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(string start)
{
    map<string, int> visited;
    queue<string> q;

    visited[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        if (cur == "123456780")
            return visited[cur];

        int zero = cur.find('0');
        int x = zero / 3;
        int y = zero % 3;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3)
                continue;

            int pos = nx * 3 + ny;

            string next = cur;
            char temp = next[zero];
            next[zero] = next[pos];
            next[pos] = temp;

            if (visited[next] == 0)
            {
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string start = "";

    for (int i = 0; i < 9; i++)
    {
        int num;
        cin >> num;
        start += (num + '0');
    }

    cout << bfs(start) << "\n";
    return 0;
}
