#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
    int x1, x2, y, idx;
};

vector<int> parent;
vector<info> logs;

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa != pb) parent[pa] = pb;
}

bool comp(info& a, info& b) {
    return a.x1 < b.x1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    logs.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        parent[i] = i;
        logs[i] = {x1, x2, y, i};
    }

    sort(logs.begin() + 1, logs.end(), comp);

    int tmp = logs[1].x2;
    int last = logs[1].idx;
    for(int i = 2; i <= n; i++) {
        if(logs[i].x1 <= tmp) {
            uni(last, logs[i].idx);
            tmp = max(tmp, logs[i].x2);
        } else {
            tmp = logs[i].x2;
        }
        last = logs[i].idx;
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}