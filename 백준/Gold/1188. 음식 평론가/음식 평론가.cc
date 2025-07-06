#include <iostream>
#include <numeric> 
using namespace std;

int gcd(int x, int y) {
    if(x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    cout << m - gcd(n, m) << '\n'; 

    return 0;
}
