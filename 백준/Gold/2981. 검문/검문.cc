#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int calGCD(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int gcd = v[1] - v[0];
    for (int i = 2; i < n; i++)
        gcd = calGCD(gcd, v[i] - v[i - 1]);

    vector<int> result;
    for (int i = 2; i <= sqrt(gcd); ++i)
    {
        if (gcd % i == 0)
        {
            result.push_back(i);
            if (i != gcd / i)
                result.push_back(gcd / i);
        }
    }
    result.push_back(gcd);
    sort(result.begin(), result.end());

    for (int m : result)
        cout << m << " ";

    return 0;
}