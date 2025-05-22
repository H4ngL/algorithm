#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;

bool compare(pii &a, pii &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> v;
    for (int i = 0; i < n; i++)
    {
        int l, h, r;
        cin >> l >> h >> r;
        v.push_back({l, h});
        v.push_back({r, -h});
    }

    sort(v.begin(), v.end(), compare);

    multiset<int> set;
    set.insert(0);
    int max = 0;

    for (pii cur : v)
    {
        int x = cur.first;
        int h = cur.second;

        if (h > 0)
            set.insert(h);
        else
            set.erase(set.find(-h));

        int curMax = *set.rbegin();
        if (max != curMax)
        {
            cout << x << " " << curMax << " ";
            max = curMax;
        }
    }

    return 0;
}