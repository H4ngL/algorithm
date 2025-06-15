#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int d(int n) {
  return (n * 2) % 10000;
}

int s(int n) {
  return n == 0 ? 9999 : n - 1;
}

int l(int n) {
  return (n % 1000) * 10 + (n / 1000);
}

int r(int n) {
  return (n % 10) * 1000 + (n / 10);
}

string bfs(int a, int b) {
  vector<bool> visited(10000, false);
  queue<pair<int, string>> q;
  q.push({a, ""});
  visited[a] = true;

  while (!q.empty()) {
    int cur = q.front().first;
    string cmd = q.front().second;
    q.pop();

    int nextStates[4] = { d(cur), s(cur), l(cur), r(cur) };
    char ops[4] = { 'D', 'S', 'L', 'R' };

    for (int i = 0; i < 4; i++) {
      int next = nextStates[i];
      if (!visited[next]) {
        if (next == b) return cmd + ops[i];
        visited[next] = true;
        q.push({next, cmd + ops[i]});
      }
    }
  }

  return "";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << bfs(a, b) << '\n';
  }

  return 0;
}
