#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
int board[21][21];
int dir[5];

void up()
{
    for (int j = 0; j < n; j++)
    {
        vector<int> tmp(n, 0);
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (board[i][j] != 0)
                tmp[idx++] = board[i][j];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (tmp[i] != 0 && tmp[i] == tmp[i + 1])
            {
                tmp[i] <<= 1;
                tmp[i + 1] = 0;
                ans = max(ans, tmp[i]);
            }
        }

        idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (tmp[i] != 0)
                board[idx++][j] = tmp[i];
        }
        while (idx < n)
            board[idx++][j] = 0;
    }
}

void down()
{
    for (int j = 0; j < n; j++)
    {
        vector<int> tmp(n, 0);
        int idx = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (board[i][j] != 0)
                tmp[idx--] = board[i][j];
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (tmp[i] != 0 && tmp[i] == tmp[i - 1])
            {
                tmp[i] <<= 1;
                tmp[i - 1] = 0;
                ans = max(ans, tmp[i]);
            }
        }

        idx = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (tmp[i] != 0)
                board[idx--][j] = tmp[i];
        }
        while (idx >= 0)
            board[idx--][j] = 0;
    }
}

void left()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp(n, 0);
        int idx = 0;
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 0)
                tmp[idx++] = board[i][j];
        }

        for (int j = 0; j < n - 1; j++)
        {
            if (tmp[j] != 0 && tmp[j] == tmp[j + 1])
            {
                tmp[j] <<= 1;
                tmp[j + 1] = 0;
                ans = max(ans, tmp[j]);
            }
        }

        idx = 0;
        for (int j = 0; j < n; j++)
        {
            if (tmp[j] != 0)
                board[i][idx++] = tmp[j];
        }
        while (idx < n)
            board[i][idx++] = 0;
    }
}

void right()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp(n, 0);
        int idx = n - 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (board[i][j] != 0)
                tmp[idx--] = board[i][j];
        }

        for (int j = n - 1; j > 0; j--)
        {
            if (tmp[j] != 0 && tmp[j] == tmp[j - 1])
            {
                tmp[j] <<= 1;
                tmp[j - 1] = 0;
                ans = max(ans, tmp[j]);
            }
        }

        idx = n - 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (tmp[j] != 0)
                board[i][idx--] = tmp[j];
        }
        while (idx >= 0)
            board[i][idx--] = 0;
    }
}

void simulate()
{
    int backup[21][21];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            backup[i][j] = board[i][j];

    for (int i = 0; i < 5; i++)
    {
        if (dir[i] == 0)
            up();
        else if (dir[i] == 1)
            down();
        else if (dir[i] == 2)
            left();
        else if (dir[i] == 3)
            right();
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = backup[i][j];
}

void calCases(int cnt)
{
    if (cnt == 5)
    {
        simulate();
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        dir[cnt] = i;
        calCases(cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            ans = max(ans, board[i][j]);
        }
    }

    calCases(0);
    cout << ans << "\n";

    return 0;
}