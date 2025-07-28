#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int n, t;
unordered_map<int, vector<int>> rock; 
set<pii> visited;

bool valid(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) <= 2 && abs(y1 - y2) <= 2;
}

int bfs() {
    queue<pair<pii, int>> q;
    q.push({{0, 0}, 0});
    visited.insert({0, 0});

    while (!q.empty()) {
        auto [pos, cnt] = q.front(); 
        q.pop();

        int cx = pos.first;
        int cy = pos.second;

        if (cy == t) return cnt;

        for (int dy = -2; dy <= 2; dy++) {
            int ny = cy + dy;
            if (rock.find(ny) == rock.end()) continue;

            for (int nx : rock[ny]) {
                if (visited.count({nx, ny})) continue;
                if (valid(cx, cy, nx, ny)) {
                    visited.insert({nx, ny});
                    q.push({{nx, ny}, cnt + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        rock[y].push_back(x);
    }

    cout << bfs() << '\n';
    return 0;
}
