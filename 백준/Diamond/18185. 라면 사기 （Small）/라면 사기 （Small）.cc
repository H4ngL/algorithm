#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    int cost = 0;

    // 최대 cost로 초기화
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cost += 3 * v[i];
    }

    // 연속 3개를 살 수 있다면 업데이트
    for (int i = 2; i < n; i++)
    {
        if (v[i - 1] > v[i])
        {
            int minValue = min(v[i - 2], v[i - 1] - v[i]);
            cost -= (minValue * 3) * 2;
            cost += 5 * minValue;
            v[i - 2] -= minValue;
            v[i - 1] -= minValue;
        }

        if (v[i - 2] > 0 && v[i - 1] > 0 && v[i] > 0)
        {
            int minValue = min(v[i - 2], min(v[i - 1], v[i]));
            cost -= (minValue * 3) * 3;
            cost += 7 * minValue;
            for (int j = i - 2; j <= i; j++)
                v[j] -= minValue;
        }
    }

    // 연속 2개를 살 수 있다면 업데이트
    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] > 0 && v[i] > 0)
        {
            int minValue = min(v[i - 1], v[i]);
            cost -= (minValue * 3) * 2;
            cost += 5 * minValue;
            v[i - 1] -= minValue;
            v[i] -= minValue;
        }
    }

    cout << cost << endl;
    return 0;
}