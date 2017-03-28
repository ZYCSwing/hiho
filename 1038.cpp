#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> need(n), value(n);

    for (int i = 0; i < n; ++i) cin >> need[i] >> value[i];

    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int v = m; v >= need[i]; --v) {
            dp[v] = max(dp[v], dp[v - need[i]] + value[i]);
        }
    }

    cout << dp[m];

    return 0;
}