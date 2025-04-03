#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class segment_tree {
private:
  vector<pii> tree;
public:
  segment_tree(int n) {
    tree.resize(n * 4);
  }
  
  void init(int start, int end, int node, vector<ll>& v) {
    if(start == end) tree[node] = { v[start], 0 };
    else {
      int mid = (start + end) / 2;
      init(start, mid, node * 2, v);
      init(mid + 1, end, node * 2 + 1, v);
      tree[node] = maxPair(tree[node * 2], tree[node * 2 + 1]);
    }
  }
  
  void update(int idx, int value, int start, int end, int node) {
    if(idx < start || idx > end) return;
    if(start == end) {
      tree[node] = { value, 0 };
    } else {
      int mid = (start + end) / 2;
      update(idx, value, start, mid, node * 2);
      update(idx, value, mid + 1, end, node * 2 + 1);
      tree[node] = maxPair(tree[node * 2], tree[node * 2 + 1]);
    }
  }
  
  pii query(int left, int right, int start, int end, int node) {
    if(left > end || right < start) return { 0, 0 };
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    pii p1 = query(left, right, start, mid, node * 2);
    pii p2 = query(left, right, mid + 1, end, node * 2 + 1);
    return maxPair(p1, p2);
  }
  
  pii maxPair(pii p1, pii p2) {
    int arr[4] = {p1.first, p1.second, p2.first, p2.second};
    sort(arr, arr + 4, greater<int>());
    return {arr[0], arr[1]};
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  segment_tree tree(n);
  
  vector<ll> v;
  v.push_back(0);
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  
  tree.init(1, n, 1, v);
  
  int m;
  cin >> m;
  while(m--) {
    int cmd;
    cin >> cmd;
    
    if(cmd == 1) {
      int idx, value;
      cin >> idx >> value;
      tree.update(idx, value, 1, n, 1);
      
    } else if(cmd == 2) {
      int l, r;
      cin >> l >> r;
      pii result = tree.query(l, r, 1, n, 1);
      cout << result.first + result.second << "\n";
    }
  }
  
  return 0;
}