#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'P')
            v[i] = 2;
        else
            v[i] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 2)
        {
            for (int j = i - k; j <= i + k; j++)
            {
                if (j < 0 || j >= n || i == j)
                    continue;
                if (v[j] == 1)
                {
                    v[j]--;
                    cnt++;
                    break;
                }
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}