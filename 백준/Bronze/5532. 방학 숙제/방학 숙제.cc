#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;

    int k = (a + c - 1) / c;
    int m = (b + d - 1) / d;

    cout << l - max(k, m) << "\n";
    return 0;
}