#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string str;
  cin >> str;
  
  vector<int> v;
  for(char c : str) {
    v.push_back(c - '0');
  }
  
  sort(v.begin(), v.end(), greater<>());
  
  for(int num : v) {
    cout << num;
  }
  
  return 0;
}