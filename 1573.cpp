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
ll power(ll base, int exp) {
    ll res = 1;
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
#define MAXN 603
#define OFFSET 201
int n;
int a[MAXN][MAXN];
int cnt[MAXN][MAXN][21];
int q;

int main() {
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[OFFSET + i][OFFSET + j]);
        }
    }

    for (int num = 1; num <= 20; ++num) {
        for (int y = 0; y < MAXN; ++y) {
            for (int x = 0; x < MAXN; ++x) {
                if (x == 0) {
                    cnt[x][y][num] = 0;
                } else {
                    if (y == 0) {
                        cnt[x][y][num] = 0;
                    } else if (x == MAXN - 1){
                        cnt[x][y][num] = 0;
                    } else {
                        cnt[x][y][num] = cnt[x - 1][y - 1][num] + cnt[x + 1][y - 1][num] - (y >= 2 ? cnt[x][y - 2][num] : 0) + (a[x][y - 1] == num ? 1 : 0) + (a[x][y] == num ? 1 : 0);
                    }
                }
            }
        }
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int xx, yy ,k;
        scanf("%d%d%d", &xx, &yy, &k);
        --xx;
        --yy;
        xx += OFFSET;
        yy += OFFSET;
        pair<int, int> right = {xx, yy + k};
        pair<int, int> up = {xx - k, yy};
        pair<int, int> down = {xx + k, yy};
        pair<int, int> left = {xx, yy - k};
        int res = 0;
        for (int num = 1; num <= 20; ++num) {
            if (k % num == 0) {
                res += cnt[right.first][right.second][num] - cnt[up.first][up.second][num] - cnt[down.fi][down.se][num] + cnt[left.fi][left.se][num];
                int xxx = xx - k, yyy = yy;
                while (xxx < xx) {
                    if (a[xxx][yyy] == num) ++res;
                    ++xxx, --yyy;
                }
                while (yyy <= yy) {
                    if (a[xxx][yyy] == num) ++res;
                    ++xxx, ++yyy;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}