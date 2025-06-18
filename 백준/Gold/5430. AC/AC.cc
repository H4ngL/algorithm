#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
      string p, arr;
      int n;
      cin >> p >> n >> arr;
      
      deque<int> dq;
      string num = "";
      for(char c : arr) {
        if(isdigit(c)) {
          num += c;
        } else if(!num.empty()) {
          dq.push_back(stoi(num));
          num = "";
        }
      }
      
      bool isReverse = false;
      bool isValid = true;
      for(char c : p) {
        if(c == 'R') isReverse = !isReverse;
        else if(c == 'D') {
          if(dq.empty()) {
            isValid = false;
            break;  
          }
          
          if(isReverse) {
            dq.pop_back();
          } else {
            dq.pop_front();
          }
        }
      }
      
      if(!isValid) cout << "error\n";
      else {
        cout << "[";
        
        if (!dq.empty()) {
          if (isReverse) {
              for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                  cout << *it;
                  if (it + 1 != dq.rend()) cout << ",";
              }
          } else {
              for (auto it = dq.begin(); it != dq.end(); ++it) {
                  cout << *it;
                  if (it + 1 != dq.end()) cout << ",";
              }
          }
        }
        
        cout << "]\n";
      }
    }
    
    return 0;
}