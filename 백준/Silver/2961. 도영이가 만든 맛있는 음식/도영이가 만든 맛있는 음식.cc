#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;
int ans = (int)1e10;

void cal(int idx, int s, int b)
{
    if (idx == v.size())
        return;

    for (int i = idx; i < v.size(); i++)
    {
        int new_s = s * v[i].first;
        int new_b = b + v[i].second;
        ans = min(ans, abs(new_s - new_b));
        cal(i + 1, new_s, new_b);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int s, b;
        cin >> s >> b;
        v.push_back({s, b});
    }

    cal(0, 1, 0);
    cout << ans << "\n";

    return 0;
}