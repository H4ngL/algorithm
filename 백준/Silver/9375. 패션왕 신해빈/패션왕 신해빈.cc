#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<string, int> hash;
        for (int i = 0; i < n; i++)
        {
            string name, type;
            cin >> name >> type;
            hash[type]++;
        }

        int ans = 1;
        for (auto i : hash)
        {
            ans *= (i.second + 1);
        }
        ans--;
        cout << ans << "\n";
    }

    return 0;
}