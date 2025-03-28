#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (i == l)
            {
                l++;
                continue;
            }
            if (i == r)
            {
                r--;
                continue;
            }

            int sum = numbers[l] + numbers[r];

            if (sum < numbers[i])
                l++;
            else if (sum > numbers[i])
                r--;
            else
            {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}