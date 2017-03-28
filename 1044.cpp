#include <iostream>
#include <vector>

using namespace std;

int lower_bit(int x) {
    return x & -x;
}

int count(int x) {
    int cnt = 0;
    while (x) {
        ++cnt;
        x -= lower_bit(x);
    }
    return cnt;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    vector<vector<int>> dp(n, vector<int>(1 << m, 0));

    int res = 0;
    dp[0][0] = 0;
    dp[0][1] = w[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < (1 << min(m, i + 1)); ++j) {
            if (count(j) > q) continue;
            if (j & 1) {
                dp[i][j] = max(dp[i][j], max(dp[i - 1][(j >> 1) | (1 << m - 1)], dp[i - 1][j >> 1]) + w[i]);
            } else {
                dp[i][j] = max(dp[i][j], max(dp[i - 1][(j >> 1) | (1 << m - 1)], dp[i - 1][j >> 1]));
            }
            if (i == n - 1) {
                res = max(res, dp[i][j]);
            }
        }
    }

    cout << res;

    return 0;
}