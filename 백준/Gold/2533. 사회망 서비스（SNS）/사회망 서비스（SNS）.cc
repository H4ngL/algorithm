#include <iostream>
#include <vector>
using namespace std;

int dp[1000001][2];
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;

    for (int child : adj[node])
    {
        if (!visited[child])
        {
            dfs(child);
            dp[node][0] += dp[child][1];
            dp[node][1] += min(dp[child][0], dp[child][1]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    adj.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}