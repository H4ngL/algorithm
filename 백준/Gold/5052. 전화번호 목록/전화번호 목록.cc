#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode {
    TrieNode* child[10];  
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 10; i++) child[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    bool insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - '0';
            if (!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];

            if (node->isEnd) return false;  
        }
        node->isEnd = true;

        for (int i = 0; i < 10; i++) {
            if (node->child[i]) return false;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        Trie trie;
        int n;
        cin >> n;
        vector<string> v(n);
        
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());

        bool flag = true;
        for (string& str : v) {
            if (!trie.insert(str)) { 
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << "\n";
    }

    return 0;
}
