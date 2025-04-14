#include <iostream>
using namespace std;

bool isPalindrome(string str)
{
    int l = 0, r = str.size() - 1;

    while (l < r)
    {
        if (str[l] != str[r])
            return false;
        l++;
        r--;
    }

    return true;
}

bool isPseudoPalindrome(string str)
{
    int l = 0, r = str.size() - 1;

    while (l < r)
    {
        if (str[l] != str[r])
        {
            return isPalindrome(str.substr(l, r - l)) || isPalindrome(str.substr(l + 1, r - l));
        }
        l++;
        r--;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;

        if (isPalindrome(str))
            cout << "0" << "\n";
        else if (isPseudoPalindrome(str))
            cout << "1" << "\n";
        else
            cout << "2" << "\n";
    }

    return 0;
}