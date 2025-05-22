#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cx, cy, ans = 0;
    cin >> cx >> cy;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        if (cx <= x && x <= cy)
        {
            if (cy < y)
                cy = y;
        }
        else
        {
            ans += cy - cx;
            cx = x;
            cy = y;
        }
    }

    ans += cy - cx;
    cout << ans << "\n";
    return 0;
}