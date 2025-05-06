#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;

        multiset<int> s;
        vector<int> v;
        for (int i = 1; i <= m; i++)
        {
            int num;
            cin >> num;
            s.insert(num);

            if (i % 2 == 1)
            {
                auto it = s.begin();
                advance(it, s.size() / 2);
                v.push_back(*it);
            }
        }

        cout << v.size() << "\n";
        for (int i = 1; i <= v.size(); i++)
        {
            cout << v[i - 1] << " ";
            if (i % 10 == 0 && i != v.size())
                cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}