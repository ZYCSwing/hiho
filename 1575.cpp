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
#define MAXN 51
bool visited[MAXN][MAXN][MAXN][MAXN];
int n, m;
string grid[MAXN];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main() {
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int x0 = 0, y0 = 0, x1 = n - 1, y1 = m - 1;
    queue<vector<int>> qq;
    qq.push({x0, y0, x1, y1, 0});
    visited[x0][y0][x1][y1] = true;
    int res = -1;
    while (!qq.empty()) {
        vector<int> vec = qq.front();
        qq.pop();
        if (vec[0] == n - 1 && vec[1] == m - 1 && vec[2] == 0 && vec[3] == 0) {
            res = vec[4];
            break;
        }
        for (int i = 0; i < 2; ++i) {
            vector<int> next(5);
            next[0] = vec[0] + dx[i];
            next[1] = vec[1] + dy[i];
            if (next[0] == n || next[1] == m || grid[next[0]][next[1]] == '1') {
                next[0] = vec[0];
                next[1] = vec[1];
            }
            next[2] = vec[2] - dx[i];
            next[3] = vec[3] - dy[i];
            if (next[2] == -1|| next[3] == -1 || grid[next[2]][next[3]] == '1') {
                next[2] = vec[2];
                next[3] = vec[3];
            }
            next[4] = vec[4] + 1;
            // exchange
            if (next[0] == vec[2] && next[1] == vec[3] && next[2] == vec[0] && next[3] == vec[1]) continue;
            // same
            if (next[0] == next[2] && next[1] == next[3]) continue;
            if (visited[next[0]][next[1]][next[2]][next[3]]) continue;
            visited[next[0]][next[1]][next[2]][next[3]] = true;
            qq.push(next);
        }
    }

    // consider -1
    cout << res;

    return 0;
}