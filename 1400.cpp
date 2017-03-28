#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    string str;
    vector<unordered_set<int>> foo(26);

    cin >> n >> str >> m;
    for (int i = 0; i < m; ++i) {
        string tmp;
        cin >> tmp;
        foo[tmp[0] - 'a'].insert(tmp[1] - 'a');
        foo[tmp[1] - 'a'].insert(tmp[0] - 'a');
    }

    vector<int> dp(26, 0);

    dp[str[0] - 'a'] = 1;
    for (int i = 1; i < n; ++i) {
        int ch = str[i] - 'a';
        int tmp = 1;
        for (int j = 0; j < 26; ++j) {
            if (foo[ch].find(j) == foo[ch].end()) {
                tmp = max(tmp, dp[j] + 1);
            }
        }
        dp[ch] = tmp;
    }
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        res = max(res, dp[i]);
    }
    cout << str.length() - res;

    return 0;
}