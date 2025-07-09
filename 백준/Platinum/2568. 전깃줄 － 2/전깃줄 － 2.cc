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

    // v : lis 크기를 구하기 위한 배열
    // v_idx : v에 push되는 숫자의 index 저장
    // prev : 전 index 저장
    // pos : 위치 매핑
    vector<int> v, v_idx, prev(n, -1), pos(n);
    for(int i = 0; i < n; i++) {
        int idx = lower_bound(v.begin(), v.end(), wire[i].second) - v.begin();

        if(idx == v.size()) {
            v.push_back(wire[i].second);
            v_idx.push_back(i);
        } else {
            v[idx] = wire[i].second;
            v_idx[idx] = i;
        }

        pos[i] = idx;
        if(idx > 0) {
            prev[i] = v_idx[idx - 1];
        }
    }

    // lis에 포함된 A 전봇대 번호 수집
    vector<int> lis_idx_set;
    int lis_idx = v_idx.back();
    for(int i = v.size() - 1; i >= 0; i--) {
        lis_idx_set.push_back(lis_idx);
        lis_idx = prev[lis_idx];
    }

    sort(lis_idx_set.begin(), lis_idx_set.end());
    vector<int> remove_wire;

    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(idx < lis_idx_set.size() && i == lis_idx_set[idx]) {
            idx++;
        } else {
            remove_wire.push_back(wire[i].first);
        }
    }

    sort(remove_wire.begin(), remove_wire.end());

    cout << n - v.size() << '\n';
    for(int num : remove_wire) {
        cout << num << '\n';
    }

    return 0;
}