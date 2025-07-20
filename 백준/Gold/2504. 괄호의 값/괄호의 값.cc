#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> st;
    int sum = 0, level = 1;
    for(int i = 0; i < str.size(); i++) {
        char c = str[i];

        if(c == '(') {
            st.push(c);
            level *= 2;
        } else if(c == '[') {
            st.push(c);
            level *= 3;
        } else if(c == ')') {
            if(st.empty() || st.top() != '(') {
                sum = 0;
                break;
            }

            if(str[i - 1] == '(') sum += level;
            st.pop();
            level /= 2;
        } else if(c == ']') {
            if(st.empty() || st.top() != '[') {
                sum = 0;
                break;
            }

            if(str[i - 1] == '[') sum += level; 
            st.pop();
            level /= 3;
        }
    }

    if(!st.empty()) sum = 0;
    cout << sum << '\n';

    return 0;
}