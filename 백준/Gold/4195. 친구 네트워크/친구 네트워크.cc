#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int f;
        cin >> f;

        // set을 포인터로 관리 
        unordered_map<string, unordered_set<string>*> network;

        for (int i = 0; i < f; i++) {
            string a, b;
            cin >> a >> b;

            // 포인터로 주었으므로 자동 할당 대신 직접 할당 
            if (network[a] == nullptr) {
                network[a] = new unordered_set<string>();
                network[a]->insert(a);
            }
            if (network[b] == nullptr) {
                network[b] = new unordered_set<string>();
                network[b]->insert(b);
            }

            unordered_set<string>* netA = network[a];
            unordered_set<string>* netB = network[b];

            // 포인터라 주소만 비교하므로 O(1)
            if (netA != netB) {
                if (netA->size() < netB->size())
                    swap(netA, netB);

                // 수정이 불가능하므로 const 써야 함 
                for (const string& person : *netB) {
                    netA->insert(person);
                    network[person] = netA;
                }

                delete netB;
            }

            cout << network[a]->size() << '\n';
        }
    }

    return 0;
}
