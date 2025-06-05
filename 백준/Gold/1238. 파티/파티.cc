#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9
typedef pair<int, int> pii;

int n, m, x;
vector<pii> graph[1001];

int dijkstra(int start, int end)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cost, now] = pq.top();
        pq.pop();

        if (cost > dist[now])
            continue;

        for (auto [next, time] : graph[now])
        {
            if (dist[next] > cost + time)
            {
                dist[next] = cost + time;
                pq.push({dist[next], next});
            }
        }
    }

    return dist[end];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        graph[s].push_back({e, t});
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int time = dijkstra(i, x);
        time += dijkstra(x, i);
        ans = max(ans, time);
    }
    cout << ans << '\n';

    return 0;
}