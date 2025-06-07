#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    vector<int> v(str.size() - 1);
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == '*')
            v[i] = -1;
        else
            v[i] = str[i] - '0';
    }
    int check = str[str.size() - 1] - '0';

    for (int i = 0; i <= 9; i++)
    {
        int sum = 0;
        for (int j = 0; j < 12; j++)
        {
            if (j % 2 == 0)
                sum += v[j] == -1 ? i : v[j];
            else
                sum += (v[j] == -1 ? i : v[j]) * 3;
        }
        sum += check;
        if (sum % 10 == 0)
        {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}