#include <iostream>
#include <unordered_map>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    unordered_map<string, string> map;
    for(int i = 0; i < n; i++) {
      string address, password;
      cin >> address >> password;
      map[address] = password;
    }
    
    for(int i = 0; i < m; i++) {
      string str;
      cin >> str;
      cout << map[str] << "\n";
    }
    
    return 0;
}