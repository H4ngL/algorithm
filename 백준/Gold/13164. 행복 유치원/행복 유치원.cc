#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> cost(n - 1);
    for (int i = 1; i < n; i++)
        cost[i - 1] = v[i] - v[i - 1];

    sort(cost.begin(), cost.end());

    int ans = 0;
    for (int i = 0; i < n - k; i++)
        ans += cost[i];

    cout << ans << '\n';

    return 0;
}