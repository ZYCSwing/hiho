#include <iostream>
using namespace std;

class TrieNode{
public:
    int cnt;
    TrieNode* children[26];
    TrieNode() {
        cnt = 0;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, string& str) {
    TrieNode* cur = root;
    for (int i = 0; i < str.length(); ++i) {
        if (cur->children[str[i] - 'a'] == nullptr) {
            cur->children[str[i] - 'a'] = new TrieNode();
        }
        cur = cur->children[str[i] - 'a'];
        ++(cur->cnt);
    }
}

int find(TrieNode* root, string& prefix) {
    TrieNode* cur = root;
    for (int i = 0; cur != nullptr && i < prefix.length(); ++i) {
        cur = cur->children[prefix[i] - 'a'];
    }
    if (cur == nullptr) return 0;
    return cur->cnt;
}

int main() {
    int n, m;
    cin >> n;

    TrieNode* root = new TrieNode();
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        insert(root, word);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        cout << find(root, word) << endl;
    }

    return 0;
}