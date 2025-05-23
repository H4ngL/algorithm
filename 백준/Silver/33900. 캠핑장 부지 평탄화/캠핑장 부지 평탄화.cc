#include <iostream>
#include <vector>
using namespace std;

int n, m, r, c;
vector<vector<int>> map;
vector<vector<int>> plan;

bool isValid(int sx, int sy)
{
    int check = map[sx][sy] - plan[0][0];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int cx = i + sx;
            int cy = j + sy;

            if (check != map[cx][cy] - plan[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c;

    map.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    plan.resize(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> plan[i][j];
    }

    int cnt = 0;
    for (int i = 0; i <= n - r; i++)
    {
        for (int j = 0; j <= m - c; j++)
        {
            if (isValid(i, j))
                cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}