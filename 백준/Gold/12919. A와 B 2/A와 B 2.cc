#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check(string current, const string &target)
{
    if (current == target)
        return true;
    if (current.length() < target.length())
        return false;

    bool ret = false;
    if (current.back() == 'A')
    {
        string tmp = current;
        tmp.pop_back();
        ret = ret || check(tmp, target);
    }
    if (current.front() == 'B')
    {
        string tmp = current;
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        ret = ret || check(tmp, target);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    cout << (check(t, s) ? '1' : '0') << '\n';
    return 0;
}
