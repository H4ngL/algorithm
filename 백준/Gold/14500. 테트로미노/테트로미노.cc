#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> p;

vector<vector<pair<int, int>>> tetrominos = {
    {{0,0}, {0,1}, {0,2}, {0,3}}, 
    {{0,0}, {1,0}, {2,0}, {3,0}}, 
    {{0,0}, {0,1}, {1,0}, {1,1}}, 
    {{0,0}, {0,1}, {0,2}, {1,1}}, 
    {{0,1}, {1,0}, {1,1}, {2,1}}, 
    {{1,0}, {1,1}, {1,2}, {0,1}}, 
    {{0,0}, {1,0}, {2,0}, {1,1}}, 
    {{0,0}, {1,0}, {2,0}, {2,1}}, 
    {{0,0}, {0,1}, {0,2}, {1,0}}, 
    {{0,0}, {0,1}, {1,1}, {2,1}}, 
    {{1,0}, {1,1}, {1,2}, {0,2}}, 
    {{0,1}, {1,1}, {2,1}, {2,0}},
    {{0,0}, {1,0}, {1,1}, {1,2}},
    {{0,0}, {0,1}, {1,0}, {2,0}},
    {{0,0}, {0,1}, {0,2}, {1,2}}, 
    {{0,1}, {0,2}, {1,0}, {1,1}}, 
    {{0,0}, {1,0}, {1,1}, {2,1}}, 
    {{0,0}, {0,1}, {1,1}, {1,2}}, 
    {{0,1}, {1,0}, {1,1}, {2,0}}  
};

int cal(int x, int y, const vector<pair<int, int>>& shape) {
  int sum = 0;
  for(auto& cur : shape) {
    int nx = x + cur.first;
    int ny = y + cur.second;
    
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
      return -1; 
    }
    sum += p[nx][ny];
  }
  return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    p.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> p[i][j];
      }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for(const auto& shape : tetrominos) {
          int sum = cal(i, j, shape);
          ans = max(sum, ans);
        }
      }
    }
    cout << ans << '\n';
    
    return 0;
}