#include <iostream>
using namespace std;

void hanoi(int n, int start, int to, int bypass) {
    if(n == 1) {
        cout << start << ' ' << to << '\n';
    } else {
        hanoi(n - 1, start, bypass, to);
        cout << start << ' ' << to << '\n';
        hanoi(n - 1, bypass, to, start);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';
    hanoi(n, 1, 3, 2);

    return 0;
}