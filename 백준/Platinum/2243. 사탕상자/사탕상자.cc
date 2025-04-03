#include <iostream>
#include <vector> 
using namespace std;
typedef long long ll;

#define MAX 1000000

class segment_tree {
private:
  vector<ll> tree;
public:
  segment_tree(int n) {
    tree.resize(n * 4);
  }

  void update(int idx, int value, int node, int start, int end) {
    if(idx < start || idx > end) return;

    if(start == end) {
      tree[node] += value;
    } else {
      int mid = (start + end) / 2;
      update(idx, value, node * 2, start, mid);
      update(idx, value, node * 2 + 1, mid + 1, end);
      tree[node] = tree[node * 2] + tree[node * 2 + 1];    
    }
  }
  
  int query(int rank, int node, int start, int end) {
      if (start == end) return start;
  
      int mid = (start + end) / 2;
      int left_size = tree[node * 2]; 
  
      if (rank <= left_size) { 
          return query(rank, node * 2, start, mid);
      } else { 
          return query(rank - left_size, node * 2 + 1, mid + 1, end);
      }
  }

};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    segment_tree tree(MAX);
    
    int n, a, b, c;
    cin >> n;
    
    while(n--) {
      cin >> a;
      
      if(a == 1) {
        cin >> b;
        int taste = tree.query(b, 1, 1, MAX);
        cout << taste << "\n";
        
        tree.update(taste, -1, 1, 1, MAX);
      } else if(a == 2) {
        cin >> b >> c;
        tree.update(b, c, 1, 1, MAX);
      }
    }
    
    return 0;
}