#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bfs(int start, int end) {
  vector<int> prev(100001, -1);   
  vector<int> dist(100001, -1);   
  queue<int> q;
  
  q.push(start);
  dist[start] = 0;

  while (!q.empty()) {
    int pos = q.front();
    q.pop();

    if (pos == end) break;

    int next[3] = { pos - 1, pos + 1, pos * 2 };
    for (int np : next) {
      if (np < 0 || np > 100000) continue;
      if (dist[np] != -1) continue;

      dist[np] = dist[pos] + 1;
      prev[np] = pos;  
      q.push(np);
    }
  }

  vector<int> path;
  for (int i = end; i != -1; i = prev[i]) {
    path.push_back(i);
  }
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, k;
  cin >> n >> k;

  vector<int> path = bfs(n, k);
  cout << path.size() - 1 << '\n';  
  for (int x : path) {
    cout << x << ' ';
  }

  return 0;
}
