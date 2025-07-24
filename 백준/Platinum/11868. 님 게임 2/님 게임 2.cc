#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cal = 0;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cal ^= num;
    }

    if(cal) cout << "koosaga" << '\n';
    else cout << "cubelover" << '\n';

    return 0;
}