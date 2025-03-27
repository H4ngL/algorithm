#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v;

class segment_tree
{
private:
    vector<ll> tree;
    vector<ll> lazy;

public:
    segment_tree(int n)
    {
        tree.resize(n * 4);
        lazy.resize(n * 4);
    }

    void init(int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        init(start, mid, node * 2);
        init(mid + 1, end, node * 2 + 1);
    }

    void propagate(int start, int end, int node)
    {
        if (lazy[node] != 0)
        {
            tree[node] ^= lazy[node];

            if (start != end)
            {
                lazy[node * 2] ^= lazy[node];
                lazy[node * 2 + 1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int start, int end, int node, int left, int right, int value)
    {
        propagate(start, end, node);

        if (start > right || end < left)
            return;

        if (left <= start && end <= right)
        {
            lazy[node] ^= value;
            return;
        }

        int mid = (start + end) / 2;
        update(start, mid, node * 2, left, right, value);
        update(mid + 1, end, node * 2 + 1, left, right, value);
    }

    ll query(int start, int end, int node, int idx)
    {
        propagate(start, end, node);
        if (start == end)
            return tree[node];

        int mid = (start + end) / 2;
        if (idx <= mid)
            return query(start, mid, node * 2, idx);
        else
            return query(mid + 1, end, node * 2 + 1, idx);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n;

    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    segment_tree tree(n);
    tree.init(1, n, 1);

    cin >> m;
    while (m--)
    {
        cin >> t;
        if (t == 1)
        {
            int a, b, c;
            cin >> a >> b >> c;
            tree.update(0, n - 1, 1, a, b, c);
        }
        else if (t == 2)
        {
            int a;
            cin >> a;
            cout << tree.query(0, n - 1, 1, a) << "\n";
        }
    }

    return 0;
}
