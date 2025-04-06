#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007

class segment_tree
{
private:
    vector<ll> tree;
    vector<ll> addLazy;
    vector<ll> mulLazy;

public:
    segment_tree(int n)
    {
        tree.resize(n * 4);
        addLazy.resize(n * 4);
        mulLazy.resize(n * 4, 1);
    }

    void init(int start, int end, int node, vector<int> &v)
    {
        if (start == end)
            tree[node] = v[start];
        else
        {
            int mid = (start + end) / 2;
            init(start, mid, node * 2, v);
            init(mid + 1, end, node * 2 + 1, v);
            tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
        }
    }

    void propagate(int start, int end, int node)
    {
        if (mulLazy[node] != 1 || addLazy[node] != 0)
        {
            tree[node] = (tree[node] * mulLazy[node]) % MOD;
            tree[node] = (tree[node] + (end - start + 1) * addLazy[node]) % MOD;

            if (start != end)
            {
                mulLazy[node * 2] = (mulLazy[node * 2] * mulLazy[node]) % MOD;
                addLazy[node * 2] = (addLazy[node * 2] * mulLazy[node]) % MOD;
                addLazy[node * 2] = (addLazy[node * 2] + addLazy[node]) % MOD;

                mulLazy[node * 2 + 1] = (mulLazy[node * 2 + 1] * mulLazy[node]) % MOD;
                addLazy[node * 2 + 1] = (addLazy[node * 2 + 1] * mulLazy[node]) % MOD;
                addLazy[node * 2 + 1] = (addLazy[node * 2 + 1] + addLazy[node]) % MOD;
            }

            mulLazy[node] = 1;
            addLazy[node] = 0;
        }
    }

    void updateAdd(int start, int end, int node, int left, int right, int value)
    {
        propagate(start, end, node);
        if (right < start || end < left)
            return;
        if (left <= start && end <= right)
        {
            addLazy[node] = (addLazy[node] + value) % MOD;
            propagate(start, end, node);
            return;
        }

        int mid = (start + end) / 2;
        updateAdd(start, mid, node * 2, left, right, value);
        updateAdd(mid + 1, end, node * 2 + 1, left, right, value);
        tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
    }

    void updateMul(int start, int end, int node, int left, int right, int value)
    {
        propagate(start, end, node);
        if (right < start || end < left)
            return;
        if (left <= start && end <= right)
        {
            mulLazy[node] = (mulLazy[node] * value) % MOD;
            addLazy[node] = (addLazy[node] * value) % MOD;
            propagate(start, end, node);
            return;
        }

        int mid = (start + end) / 2;
        updateMul(start, mid, node * 2, left, right, value);
        updateMul(mid + 1, end, node * 2 + 1, left, right, value);
        tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
    }

    ll query(int start, int end, int node, int left, int right)
    {
        propagate(start, end, node);
        if (right < start || end < left)
            return 0;
        if (left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;
        ll lv = query(start, mid, node * 2, left, right);
        ll rv = query(mid + 1, end, node * 2 + 1, left, right);
        return (lv + rv) % MOD;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c, d;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    segment_tree tree(n);
    tree.init(1, n, 1, v);

    cin >> m;
    while (m--)
    {
        cin >> a;

        if (a == 1)
        {
            cin >> b >> c >> d;
            tree.updateAdd(1, n, 1, b, c, d);
        }
        else if (a == 2)
        {
            cin >> b >> c >> d;
            tree.updateMul(1, n, 1, b, c, d);
        }
        else if (a == 3)
        {
            cin >> b >> c >> d;
            tree.updateMul(1, n, 1, b, c, 0);
            tree.updateAdd(1, n, 1, b, c, d);
        }
        else if (a == 4)
        {
            cin >> b >> c;
            cout << tree.query(1, n, 1, b, c) << "\n";
        }
    }

    return 0;
}