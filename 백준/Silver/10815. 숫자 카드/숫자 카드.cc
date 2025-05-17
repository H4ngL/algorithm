#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++)
        cin >> cards[i];
    sort(cards.begin(), cards.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << binary_search(cards.begin(), cards.end(), num) << " ";
    }

    return 0;
}