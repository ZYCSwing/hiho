#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <memory.h>
using namespace std;

typedef pair<int, int> pii;
int dp[1001][1024];
int v[1001], mask[1001];
int n, m;

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(mask, 0, sizeof(mask));
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            int k;
            cin >> v[i] >> k;

            for (int j = 0; j < k; ++j) {
                int foo;
                cin >> foo;
                mask[i] |= 1 << (foo - 1);
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int mm = 0; mm < (1 << m); ++mm) {
                dp[i][mm] = dp[i - 1][mm];
                if (dp[i - 1][mm ^ mask[i]] != -1) {
                    dp[i][mm] = max(dp[i][mm], dp[i - 1][mm ^ mask[i]] + v[i]);
                }
            }
        }

        cout << dp[n][(1 << m) - 1] << endl;
    }

    return 0;
}