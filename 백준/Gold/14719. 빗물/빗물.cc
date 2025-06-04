#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w, ans = 0;
    cin >> h >> w;

    vector<int> v(w);
    for (int i = 0; i < w; i++)
        cin >> v[i];

    for (int i = 1; i < w - 1; i++)
    {
        int l = 0, r = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[i] < v[j])
                l = max(l, v[j]);
        }
        for (int j = i + 1; j < w; j++)
        {
            if (v[i] < v[j])
                r = max(r, v[j]);
        }
        if (l && r)
            ans += min(l, r) - v[i];
    }

    cout << ans << "\n";
    return 0;
}