#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct segment_tree {
private:
    vector<ll> tree;
public:
    segment_tree(int n) {
        tree.resize(n * 4);
    }

    // 영화 위치 업데이트
    void update(int start, int end, int node, int idx, int value) {
        if(idx < start || idx > end) return;
        if(start == end) {
            tree[node] += value;
            return;
        }

        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, value);
        update(mid + 1, end, node * 2 + 1, idx, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // 범위 내에 있는 영화 개수 출력 
    ll query(int start, int end, int node, int left, int right) {
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        // 1 ~ m까지는 영화를 위로 올릴 추가 공간, m + 1 ~ m + n + 1까지는 영화 초기 위치
        int size = n + m + 1;
        segment_tree tree(size);
        vector<int> v(n + 1);

        // 초기화
        for(int i = 1; i <= n; i++) {
            v[i] = m + i;
            tree.update(1, size, 1, v[i], 1);
        }

        // 가장 위에 쌓일 위치
        int top = m;

        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;

            cout << tree.query(1, size, 1, 1, v[x] - 1) << ' ';
            tree.update(1, size, 1, v[x], -1);
            
            v[x] = top--;
            tree.update(1, size, 1, v[x], 1);
        }
        cout << '\n';
    }

    return 0;
}