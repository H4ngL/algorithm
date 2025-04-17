#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

string standard;
unordered_map<char, int> map;

bool isSimilar(string str)
{
    int len1 = standard.length();
    int len2 = str.length();

    if (abs(len1 - len2) > 1)
        return false;

    unordered_map<char, int> curMap;
    for (char c : str)
        curMap[c]++;

    int diff = 0;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        diff += abs(map[c] - curMap[c]);
    }

    return diff <= 1 || (diff == 2 && len1 == len2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cin >> standard;
    for (char c : standard)
        map[c]++;

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        string str;
        cin >> str;
        if (isSimilar(str))
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}