#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        if (st.empty())
        {
            if (y > 0)
                st.push(y);
        }
        else if (y == 0)
        {
            cnt += st.size();
            while (!st.empty())
                st.pop();
        }
        else
        {
            if (st.top() > y)
            {
                while (true)
                {
                    st.pop();
                    cnt++;
                    if (st.empty() || st.top() < y)
                    {
                        st.push(y);
                        break;
                    }
                    else if (st.top() == y)
                        break;
                }
            }
            else if (st.top() < y)
                st.push(y);
        }
    }

    cnt += st.size();
    cout << cnt << "\n";
    return 0;
}