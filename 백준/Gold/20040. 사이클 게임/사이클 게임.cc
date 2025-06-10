#include <iostream>
using namespace std;

int parent[500001];

int find(int x) {
  if(parent[x] != x) {
    parent[x] = find(parent[x]);
  }
  return parent[x];
}

void uni(int x, int y) {
  int px = find(x);
  int py = find(y);
  
  if(px < py) {
    parent[py] = px;
  } else if(py < px) {
    parent[px] = py;
  }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
      parent[i] = i;
    }
    
    for(int i = 1; i <= m; i++) {
      int a, b;
      cin >> a >> b;
      if(find(a) == find(b)) {
        cout << i << "\n";
        return 0;
      }
      uni(a, b);
    }
    
    cout << "0" << "\n";
    return 0;
}