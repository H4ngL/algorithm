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
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }

    void propagate(int start, int end, int node)
    {
        if (lazy[node] != 0)
        {
            int len = end - start + 1;
            if (len % 2 == 1)
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
            propagate(start, end, node);
            return;
        }

        int mid = (start + end) / 2;
        update(start, mid, node * 2, left, right, value);
        update(mid + 1, end, node * 2 + 1, left, right, value);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }

    ll query(int start, int end, int node, int left, int right)
    {
        propagate(start, end, node);

        if (start > right || end < left)
            return 0;
        if (left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;
        ll lv = query(start, mid, node * 2, left, right);
        ll rv = query(mid + 1, end, node * 2 + 1, left, right);
        return lv ^ rv;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    segment_tree tree(n);
    tree.init(0, n - 1, 1);

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
            int a, b;
            cin >> a >> b;
            cout << tree.query(0, n - 1, 1, a, b) << "\n";
        }
    }

    return 0;
}