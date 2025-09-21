#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, x, s;
  cin >> n >> x >> s;
  
  bool check = false;
  for(int i = 0; i < n; i++) {
    int c, p;
    cin >> c >> p;
    if(c <= x && s < p) check = true;
  }
  
  string ans = check ? "YES" : "NO";
  cout << ans;
  
  return 0;
}