#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, num;
    cin >> n >> m;

    vector<int> a;
    for(int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }

    sort(a.begin(), a.end());

    int l = 0, r = 1;
    int ans = a[n - 1] - a[0];
    while(l < n && r < n) {
        int tmp = a[r] - a[l];
        if(tmp == m) {
            ans = m;
            break;
        }

        if(tmp < m) {
            r++;
            continue;
        }

        l++;
        ans = min(ans, tmp);
    }

    cout << ans << '\n';

    return 0;
}