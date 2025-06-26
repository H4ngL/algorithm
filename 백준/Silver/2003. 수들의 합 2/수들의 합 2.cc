#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, result, cnt = 0;
    cin >> n >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
      for(int j = i; j < n; j++) {
        result += a[j];
        
        if(result == m) {
          cnt++;
          result = 0;
          break;
        }
      }
      
      if(result != 0) result = 0;
    }
    
    cout << cnt << '\n';
    
    return 0;
}