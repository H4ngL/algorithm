#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  
  if(x > y) cout << x + y << '\n';
  else if(x < y) cout << y - x << '\n';
  else cout << 0 << '\n';
  
  return 0;
}