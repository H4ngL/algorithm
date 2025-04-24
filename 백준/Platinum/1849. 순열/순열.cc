#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class segment_tree
{
private:
    vector<ll> tree;

public:
    segment_tree(int n)
    {
        tree.resize(n * 4);
    }

    void init(int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = 1;
            return;
        }

        int mid = (start + end) / 2;
        init(start, mid, node * 2);
        init(mid + 1, end, node * 2 + 1);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int start, int end, int node, int idx)
    {
        if (idx < start || idx > end)
            return;
        if (start == end)
            tree[node] = 0;
        else
        {
            int mid = (start + end) / 2;
            update(start, mid, node * 2, idx);
            update(mid + 1, end, node * 2 + 1, idx);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    ll query(int start, int end, int node, int idx)
    {
        if (start == end)
            return start;

        int left = tree[node * 2];
        int mid = (start + end) / 2;

        if (idx <= left)
            return query(start, mid, node * 2, idx);
        else
            return query(mid + 1, end, node * 2 + 1, idx - left);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    segment_tree tree(n);
    tree.init(1, n, 1);
    vector<int> result(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int pos = tree.query(1, n, 1, a[i] + 1);
        result[pos] = i;
        tree.update(1, n, 1, pos);
    }

    for (int i = 1; i <= n; i++)
        cout << result[i] << "\n";

    return 0;
}
