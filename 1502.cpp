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
#include <numeric>
#include <memory.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, int> pli;

int main() {
    int n, m, k, res = -1;
    cin >> n >> m >> k;
    vector<vector<int>> matrix(n, vector<int>(m)), sum(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            sum[i][j] = j == 0 ? matrix[i][j] : matrix[i][j] + sum[i][j - 1];
        }
    }
    for (int l = 0; l < m; ++l) {
        for (int r = l; r < m; ++r) {
            int subSum = 0;
            int u = 0, d = -1;
            while (1) {
                while (d < n && subSum <= k) {
                    res = max(res, (r - l + 1) * (d - u + 1));
                    ++d;
                    if (d < n) {
                        subSum += (l == 0 ? sum[d][r] : sum[d][r] - sum[d][l - 1]);
                    }
                }
                if (d == n) break;
                while (subSum > k) {
                    subSum -= (l == 0 ? sum[u][r] : sum[u][r] - sum[u][l - 1]);
                    ++u;
                }
            }
        }
    }
    cout << (res <= 0 ? -1 : res);

    return 0;
}