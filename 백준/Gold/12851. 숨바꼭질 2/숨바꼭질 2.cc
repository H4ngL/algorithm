#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

pii bfs(int start, int end) {
  vector<int> visited(100001, -1);
  vector<int> count(100001, 0);
  queue<int> q;
  
  q.push(start);
  visited[start] = 0;
  count[start] = 1;
  
  while(!q.empty()) {
    int pos = q.front();
    q.pop();
    
    int newPos[3] = { pos + 1, pos - 1, 2 * pos };
    for(int i = 0; i < 3; i++) {
      if(newPos[i] < 0 || newPos[i] > 100000) continue;
      
      if(visited[newPos[i]] == -1) {  
        visited[newPos[i]] = visited[pos] + 1;
        count[newPos[i]] = count[pos];
        q.push(newPos[i]);
      }
      else if(visited[newPos[i]] == visited[pos] + 1) {  
        count[newPos[i]] += count[pos];
      }
    }
  }
  
  return {visited[end], count[end]};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, k;
  cin >> n >> k;
  
  auto [totalTime, cnt] = bfs(n, k);
  cout << totalTime << '\n';
  cout << cnt << '\n';
  
  return 0;
}