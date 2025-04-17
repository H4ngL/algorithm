#include <iostream>
using namespace std;

bool isPalindrome(string str)
{
    int l = 0, r = str.length() - 1;

    while (l < r)
    {
        if (str[l] != str[r])
            return false;
        l++;
        r--;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    bool check = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != str[0])
        {
            check = false;
            break;
        }
    }

    if (check)
    {
        cout << -1 << "\n";
        return 0;
    }

    if (isPalindrome(str))
        cout << str.length() - 1 << "\n";
    else
        cout << str.length() << "\n";

    return 0;
}