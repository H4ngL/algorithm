#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    vector<int> v(k);
    vector<int> rest(k);

    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
        ans += v[i] / k;
        rest[i] = v[i] % k;
    }

    sort(rest.begin(), rest.end(), greater<int>());

    int minValue = k - 1;
    int count = 0;

    while (count < k)
    {
        minValue = min(minValue, count + rest[count]);
        count++;
    }

    cout << ans + minValue << "\n";
    return 0;
}
