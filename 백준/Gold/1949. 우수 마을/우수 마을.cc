#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001][2];
vector<int> people;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] += people[node];

    for (int child : adj[node])
    {
        if (!visited[child])
        {
            dfs(child);
            dp[node][0] += max(dp[child][0], dp[child][1]);
            dp[node][1] += dp[child][0];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    people.resize(n + 1);
    adj.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> people[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}