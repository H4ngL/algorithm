#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  vector<int> v;
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  
  int start = 0, end = n - 1;
  int ans = 987654321;
  while(start < end) {
    int sum = v[start] + v[end];
    if(abs(sum) < abs(ans)) ans = sum;
    
    if(sum < 0) start++;
    else end--;
  }
  
  cout << ans << "\n";
  
  return 0;
}