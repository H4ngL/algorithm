#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
      cin >> v[i];
    }
    
    int l = 0, r = 0;
    long long cnt = 0;
    unordered_set<int> s;
    
    while(l < n) {
      while(r < n && s.find(v[r]) == s.end()) {
        s.insert(v[r]);
        r++;
      }
      
      cnt += r - l;
      s.erase(v[l]);
      l++;
    }
    
    cout << cnt << '\n';
    return 0;
}