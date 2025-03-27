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
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    void propagate(int start, int end, int node)
    {
        if (lazy[node])
        {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int start, int end, int node, int left, int right, ll val)
    {
        propagate(start, end, node); 
        if (start > right || end < left)
            return;

        if (left <= start && end <= right)
        {
            tree[node] += (end - start + 1) * val;
            if (start != end)
            {
                lazy[node * 2] += val;
                lazy[node * 2 + 1] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        update(start, mid, node * 2, left, right, val);
        update(mid + 1, end, node * 2 + 1, left, right, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; 
    }

    ll query(int start, int end, int node, int left, int right)
    {
        propagate(start, end, node); 
        if (start > right || end < left)
            return 0;

        if (left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;
        ll lv = query(start, mid, node * 2, left, right); // 여기 꼭 ll 쓰기
        ll rv = query(mid + 1, end, node * 2 + 1, left, right);
        return lv + rv;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q, cmd;
    cin >> n;
    segment_tree tree(n);

    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        tree.update(1, n, 1, i, i, v[i] - v[i - 1]);
    }

    cin >> q;
    while (q--)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            int l, r;
            cin >> l >> r;
            tree.update(1, n, 1, l, r, 1);
            tree.update(1, n, 1, r + 1, r + 1, -(r - l + 1));
        }
        else if (cmd == 2)
        {
            int x;
            cin >> x;
            cout << tree.query(1, n, 1, 1, x) << "\n";
        }
    }

    return 0;
}