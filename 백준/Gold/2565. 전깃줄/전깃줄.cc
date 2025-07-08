#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> wire(n);
    for(int i = 0; i < n; i++) {
        cin >> wire[i].first >> wire[i].second;
    }

    sort(wire.begin(), wire.end());

    vector<int> lis;
    lis.push_back(wire[0].second);
    for(int i = 1; i < n; i++) {
        if(lis.back() < wire[i].second) {
            lis.push_back(wire[i].second);
        } else {
            int idx = lower_bound(lis.begin(), lis.end(), wire[i].second) - lis.begin();
            lis[idx] = wire[i].second;
        }
    }

    cout << n - lis.size() << '\n';

    return 0;
}