#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    if(n > m) cout << 0 << '\n';
    else {
        ll num = 1;
        for(ll i = 2; i <= n; i++) num = (num * i) % m;
        cout << num << '\n';
    }
    
    return 0;
}