#include <iostream>
#include <deque>
using namespace std;

int main() {
  int n, m, cnt = 0;;
  cin >> n >> m;
  
  deque<int> dq;
  for(int i = 1; i <= n; i++) {
    dq.push_back(i);
  }
  
  for(int i = 0; i < m; i++) {
    int idx, num; 
    cin >> num;
    
    for(int i = 0; i < dq.size(); i++) {
      if(dq[i] == num) {
        idx = i;
        break;
      }
    }
    
    if(idx <= dq.size() / 2) {
      while(true) {
        if(dq.front() == num) {
          dq.pop_front();
          break;
        }
        cnt++;
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      while(true) {
        if(dq.front() == num) {
          dq.pop_front();
          break;
        }
        cnt++;
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }
  
  cout << cnt << '\n';
  return 0;
}