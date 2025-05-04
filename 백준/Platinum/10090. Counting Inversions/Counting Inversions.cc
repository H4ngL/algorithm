#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

class segment_tree
{
private:
    vector<ll> tree;

public:
    segment_tree(int n)
    {
        tree.resize(4 * n);
    }

    void init(int start, int end, int node, vector<ll> &v)
    {
        if (start == end)
        {
            tree[node]++;
        }
        else
        {
            int mid = (start + end) / 2;
            init(start, mid, node * 2, v);
            init(mid + 1, end, node * 2 + 1, v);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(int start, int end, int node, int idx, ll val)
    {
        if (idx < start || idx > end)
            return;
        else
        {
            if (start == end)
            {
                tree[node] += 1;
            }
            else
            {
                int mid = (start + end) / 2;
                update(start, mid, node * 2, idx, val);
                update(mid + 1, end, node * 2 + 1, idx, val);
                tree[node] = tree[node * 2] + tree[node * 2 + 1];
            }
        }
    }

    ll query(int start, int end, int node, int left, int right)
    {
        if (left > end || right < start)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    ll sum = 0;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    segment_tree tree(n);

    for (int i = 1; i <= n; i++)
    {
        sum += tree.query(1, n, 1, v[i] + 1, n);
        tree.update(1, n, 1, v[i], 1);
    }

    cout << sum << "\n";
    return 0;
}