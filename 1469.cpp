#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

int main() {
    int n, res = 0;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 1)), matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            if (i && j && matrix[i][j] == matrix[i - 1][j] + 1 && matrix[i][j] == matrix[i][j - 1] + 1) {
                int tmp = min(dp[i - 1][j], dp[i][j - 1]);
                if (matrix[i - tmp][j - tmp] + 2 * tmp == matrix[i][j]) ++tmp;
                dp[i][j] = tmp;
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res;

    return 0;
}