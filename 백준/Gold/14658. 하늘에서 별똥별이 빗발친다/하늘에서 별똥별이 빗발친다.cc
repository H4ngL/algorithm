#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<pii> star;

int cal(int i, int j, int l) {
    int cnt = 0;

    for(auto [x, y] : star) {
        if(x >= i && x <= i + l && y >= j && y <= j + l) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, l, k;
    cin >> n >> m >> l >> k;

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        star.push_back({x, y});
    }

    int cnt = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            int x = star[i].first;
            int y = star[j].second;
            cnt = max(cnt, cal(x, y, l));
        }
    }

    cout << k - cnt << '\n';

    return 0;
}