#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct segment_tree {
private:
    vector<ll> tree;
public:
    segment_tree(int n) {
        tree.resize(n * 4);
    }

    // 값이 들어왔음을 표시 
    void update(int start, int end, int node, int idx) {
        if(idx < start || idx > end) return;
        if(start == end) {
            tree[node]++;
            return;
        }

        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx);
        update(mid + 1, end, node * 2 + 1, idx);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // 현재 값보다 작은 값이 트리에 몇 개 있는지 
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

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 좌표 압축(-10억 ~ 10억 범위이므로)
    vector<int> compressed = v;
    // 압축 대상 벡터를 오름차순 정렬
    sort(compressed.begin(), compressed.end());
    // 중복 제거 
    // - unique는 중복 요소를 뒤로 밀고, 중복 제거된 끝 위치를 반환
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

    // zip이라는 람다 함수 정의 
    // x를 입력시 압축된 인덱스를 반환 
    auto zip = [&](int x) {
        return lower_bound(compressed.begin(), compressed.end(), x) - compressed.begin();
    };

    segment_tree tree(compressed.size());
    ll cnt = 0;

    for(int i = n - 1; i >= 0; i--) {
        int idx = zip(v[i]);
        cnt += tree.query(0, compressed.size() - 1, 1, 0, idx - 1);
        tree.update(0, compressed.size(), 1, idx);
    }

    cout << cnt << '\n';
    return 0;
}