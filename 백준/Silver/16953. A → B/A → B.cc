#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

int bfs(ll a, ll b) {
    queue<pli> q;
    q.push({a, 1});

    while (!q.empty()) {
        ll cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == b) return cnt;

        ll next1 = cur * 2;
        ll next2 = cur * 10 + 1;

        if (next1 <= b) q.push({next1, cnt + 1});
        if (next2 <= b) q.push({next2, cnt + 1});
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;
    cout << bfs(a, b) << "\n";
    return 0;
}
