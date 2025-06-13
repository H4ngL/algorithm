#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Compare {
  bool operator()(int a, int b) {
    if(abs(a) != abs(b)) return abs(a) > abs(b);
    return a > b;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  priority_queue<int, vector<int>, Compare> pq;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x; 
    if(x == 0) {
      if(!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
      } else{
        cout << "0" << "\n";
      }
    } else {
      pq.push(x);
    }
  }
  
  return 0;
}