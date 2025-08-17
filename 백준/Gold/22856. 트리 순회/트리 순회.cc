/*
 * BOJ #22856 - 트리 순회
 * https://www.acmicpc.net/problem/22856
 * 
 * 알고리즘 분류: 그래프 탐색
 * 
 * 풀이 요약:
 * - 
 * 
 * 날짜: 2025-08-17
 */

#include <iostream>
#include <vector>
using namespace std;

struct node {
    bool visited;
    int parent;
    int left;
    int right;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<node> v(n + 1);
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].left = b;
        v[a].right = c;

        v[b].parent = a;
        v[c].parent = a;
    }

    int end = 1;
    while(true) {
        if(v[end].right != -1) {
            end = v[end].right;
        } else break;
    }

    int cur = 1;
    v[cur].visited = true;
    int cnt = 0;
    while(true) {
        int cp = v[cur].parent;
        int cl = v[cur].left;
        int cr = v[cur].right;

        if(cl > 0 && !v[cl].visited) {
            cur = cl;
            cnt++;
            v[cl].visited = true;
        } else if(cr > 0 && !v[cr].visited) {
            cur = cr;
            cnt++;
            v[cr].visited = true;
        } else if(cur == end) {
            break;
        }else if(cp > 0) {
            cur = cp;
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}