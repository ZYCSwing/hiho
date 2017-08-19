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
    vector<vector<int>> data;
    int r, c;
    Matrix(int row, int col, bool identity = false) : r(row), c(col) {
        data.assign(row, vector<int>(col, 0));
        if (identity) {
            for (int i = 0; i < r; ++i) {
                data[i][i] = 1;
            }
        }
    }
    Matrix operator * (Matrix& other) {
        int m = r, n = c, p = other.c;
        Matrix res(m, p);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < n; ++k) {
                    res.data[i][j] += data[i][k] * other.data[k][j];
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
#define MAXN 100010
int n, m;
unordered_map<char, int> mm;
char res[410][410];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void gao(int x, int y, bool block) {
    res[x][y] = block ? (x % 2 ? '|' : '-') : ' ';
}

int main() {
    mm['l'] = 0, mm['u'] = 1, mm['r'] = 2, mm['d'] = 3;
    cin >> n >> m;
    int x = 1, y = 1, dd = 3;
    for (int i = 0; i < 2 * n * m - 1; ++i) {
        int xx = 2 * x - 1, yy = 2 * y - 1;
        res[xx][yy] = ' ';
        int l, f, r;
        char d;
        cin >> l >> f >> r >> d;
        gao(xx + dx[(dd + 3) % 4], yy + dy[(dd + 3) % 4], l == 1);
        gao(xx + dx[dd], yy + dy[dd], f == 1);
        gao(xx + dx[(dd + 1) % 4], yy + dy[(dd + 1) % 4], r == 1);
        dd = mm[d];
        x += dx[dd], y += dy[dd];
    }

    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= 2 * m; ++j) {
            if (i % 2 == 0 && j % 2 == 0) {
                cout << '+';
            } else {
                cout << res[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}