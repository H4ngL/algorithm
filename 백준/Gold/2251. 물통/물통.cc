#include <iostream>
#include <algorithm>
#include <queue> 
#include <unordered_map>
#include <set>
using namespace std;

vector<int> bfs(int a, int b, int c) {
    vector<int> v;
    unordered_map<string, bool> visited;
    queue<string> q;
    set<int> s;

    string start = to_string(0) + "," + to_string(0) + "," + to_string(c);
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        string cur = q.front();
        q.pop();

        int ca, cb, cc;
        sscanf(cur.c_str(), "%d,%d,%d", &ca, &cb, &cc);

        if(ca == 0) s.insert(cc);

        int arr[3] = { ca, cb, cc };
        int cap[3] = { a, b, c };

        for(int from = 0; from < 3; from++) {
            for(int to = 0; to < 3; to++) {
                if(from == to || arr[from] == 0 || arr[to] == cap[to]) continue;

                int tmp[3] = { arr[0], arr[1], arr[2] };

                int move = min(tmp[from], cap[to] - tmp[to]);
                tmp[from] -= move;
                tmp[to] += move;

                string next = to_string(tmp[0]) + "," + to_string(tmp[1]) + "," + to_string(tmp[2]);

                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }

    for(int num : s) {
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    for(int num : bfs(a, b, c)) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}
