#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, c, ans = 0;
    cin >> n >> c;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    // 집들 사이의 간격을 기준으로 매개변수 탐색 
    int l = 1, r = v[n - 1] - v[0];
    while(l <= r) {
      int mid = (l + r) / 2;
      int cnt = 1, prev = v[0];
      for(int i = 1; i < n; i++) {
        if(v[i] - prev >= mid) {
          cnt++;
          prev = v[i];
        }
      }
      
      if(cnt >= c) {
        ans = max(ans, mid);
        l = mid + 1;
      } else r = mid - 1;
    }
    
    cout << ans << '\n';
    
    return 0;
}