#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

char map[501][501];
vector<pii> wolf;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    
    for(int i = 0; i < r; i++) {
      string str;
      cin >> str;
      for(int j = 0; j < c; j++) {
        map[i][j] = str[j];
        if(map[i][j] == 'W') {
          wolf.push_back({i, j});
        }
      }
    }
    
    bool check = true;
    for(auto [x, y] : wolf) {
      for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        
        if(map[nx][ny] == 'S') {
          check = false;
        } else if(map[nx][ny] == '.') {
          map[nx][ny] = 'D';
        }
      }
    }
    
    if(check) {
      cout << '1' << '\n';
      for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
          cout << map[i][j];
        }
        cout << '\n';
      }
    } else {
      cout << '0' << '\n';
    }
    
    return 0;
}