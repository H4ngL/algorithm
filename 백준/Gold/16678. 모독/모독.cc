#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long cnt = v[0] - 1;
    v[0] = 1;
    for(int i = 1; i < n; i++) {
        int cur = v[i - 1] + 1;
        if(v[i] > cur) {
            int gap = v[i] - cur;
            cnt += gap;
            v[i] = cur;
        }
    }

    cout << cnt << '\n';

    return 0;
}