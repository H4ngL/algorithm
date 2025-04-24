#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, ans = 0;
vector<int> v;
unordered_map<int, int> cnt;

void cal(int l, int r) {
    if (r == n) return;

    cnt[v[r]]++;

    while (cnt.size() > 2) {
        cnt[v[l]]--;
        if (cnt[v[l]] == 0) cnt.erase(v[l]);
        l++;
    }

    ans = max(ans, r - l + 1);
    cal(l, r + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cal(0, 0);
    cout << ans << "\n";

    return 0;
}
