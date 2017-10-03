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
#include <ctype.h>
using namespace std;

#define PI acos(-1.0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

#define eps 1e-8
#define mod 1000000007

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

struct Matrix {
    vector<vector<ll>> data;
    int r, c;
    Matrix(int row, int col, bool identity = false) : r(row), c(col) {
        data.assign(row, vector<ll>(col, 0));
        if (identity) {
            for (int i = 0; i < r; ++i) {
                data[i][i] = 1;
            }
        }
    }
    Matrix operator * (Matrix other) {
        int m = r, n = c, p = other.c;
        Matrix res(m, p);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < n; ++k) {
                    res.data[i][j] += data[i][k] * other.data[k][j];
                    res.data[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

// 扩展欧几里得算法 res[1] * a + res[2] * b = res[0] = gcd(a, b)
vector<int> extendGcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    } else {
        vector<int> tmp = extendGcd(b, a % b);
        return {tmp[0], tmp[2], tmp[1] - (a / b) * tmp[2]};
    }
}

// 矩阵快速幂
Matrix matrix_power(Matrix base, ll exp) {
    int n = base.r;
    Matrix res(n, n, true);
    while (exp) {
        if (exp & 1) {
            res = res * base;
        }
        base = base * base;
        exp >>= 1;
    }
    return res;
}

// 带模快速幂
ll power_mod(ll base, int exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// 快速幂
template <class T>
T power(T base, int exp) {
    T res = 1;
    while (exp) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

// 求逆元
ll inv(ll a) {
    return power_mod(a, mod - 2);
}

#define MAXFAC 100010

ll fac[MAXFAC];

void initFac() {
    fac[0] = 1;
    for (int i = 1; i < MAXFAC; ++i) {
        fac[i] = i * fac[i - 1] % mod;
    }
}

ll Combine(ll a, ll b) {
    return (fac[a] * inv(fac[b]) % mod) * inv(fac[a - b]) % mod;
}

/******************************** template ********************************/
#define MAXN 100010
int n;
vector<int> b;
ll dp[60][60][60][60];
//vector<vector<vector<vector<int>>>> dp(60, vector<vector<vector<int>>>(60, vvi(60, vector<int>(60, 0))));

int main() {
    cin >> n;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        b.pb(num);
    }
    sort(all(b));
    int dup = 1;
    for (int i = 1; i < n; ++i) {
        if (b[i] == b[0]) {
            ++dup;
        } else {
            break;
        }
    }
    if (dup > 2) {
        while (b.size() > 2 && b[2] == b[0]) {
            b.erase(b.begin() + 2);
        }
    }
    n = b.size();
    memset(dp, 0, sizeof(dp));
    dp[0][1][1][0] = dp[1][0][0][1] = 1;
    for (int i = 2; i < n; ++i) {
        int u1, u2, d1, d2;
        u2 = i - 1;
        for (u1 = 0; u1 < i - 1; ++u1) {
            for (d1 = 0; d1 <= i - 1; ++d1) {
                for (d2 = 0; d2 < i - 1; ++d2) {
                    if (d2 == d1) continue;
                    if (dp[u1][u2][d1][d2]) {
                        if (b[u1] + b[i] >= 2 * b[u2]) {
                            dp[u2][i][d1][d2] = ((ll)dp[u2][i][d1][d2] + dp[u1][u2][d1][d2]) % mod;
                        }
                        if (b[d1] + b[i] >= 2 * b[d2]) {
                            dp[u1][u2][d2][i] = ((ll)dp[u1][u2][d2][i] + dp[u1][u2][d1][d2]) % mod;
                        }
                    }
                }
            }
        }
        d2 = i - 1;
        for (u1 = 0; u1 <= i - 1; ++u1) {
            for (u2 = 0; u2 < i - 1; ++u2) {
                if (u2 == u1) continue;
                for (d1 = 0; d1 < i - 1; ++d1) {
                    if (dp[u1][u2][d1][d2]) {
                        if (b[u1] + b[i] >= 2 * b[u2]) {
                            dp[u2][i][d1][d2] = ((ll)dp[u2][i][d1][d2] + dp[u1][u2][d1][d2]) % mod;
                        }
                        if (b[d1] + b[i] >= 2 * b[d2]) {
                            dp[u1][u2][d2][i] = ((ll)dp[u1][u2][d2][i] + dp[u1][u2][d1][d2]) % mod;
                        }
                    }
                }
            }
        }
    }

    ll res = 0;
    for (int u1 = 0; u1 < n - 1; ++u1) {
        for (int d1 = 0; d1 <= n - 1; ++d1) {
            for (int d2 = 0; d2 < n - 1; ++d2) {
                if (d2 == d1) continue;
                res += dp[u1][n - 1][d1][d2];
                res %= mod;
            }
        }
    }

    for (int u1 = 0; u1 <= n - 1; ++u1) {
        for (int u2 = 0; u2 < n - 1; ++u2) {
            if (u1 == u2) continue;
            for (int d1 = 0; d1 < n - 1; ++d1) {
                res += dp[u1][u2][d1][n - 1];
                res %= mod;
            }
        }
    }

    for (int i = 3; i <= dup; ++i) {
        res = res * i % mod;
    }

    cout << res;

    return 0;
}