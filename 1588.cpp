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
class Solution {
    int gao(string s) {
        int hh = (s[0] - '0') * 10 + s[1] - '0';
        int mm = (s[3] - '0') * 10 + s[4] - '0';
        int ss = (s[6] - '0') * 10 + s[7] - '0';
        return hh * 3600 + mm * 60 + ss;
    }

    string rev(int i) {
        int hh = i / 3600;
        int mm = (i / 60) % 60;
        int ss = i % 60;

        string res;
        if (hh < 10) {
            res = "0" + to_string(hh);
        } else {
            res = to_string(hh);
        }
        res.push_back(':');
        if (mm < 10) {
            res.append("0" + to_string(mm));
        } else {
            res.append(to_string(mm));
        }
        res.push_back(':');
        if (ss < 10) {
            res.append("0" + to_string(ss));
        } else {
            res.append(to_string(ss));
        }

        return res;
    }
public:
    string nextClosestTime(string time) {
        vector<bool> foo(10, false);
        foo[time[0] - '0'] = true;
        foo[time[1] - '0'] = true;
        foo[time[3] - '0'] = true;
        foo[time[4] - '0'] = true;
        foo[time[6] - '0'] = true;
        foo[time[7] - '0'] = true;

        int start = gao(time);
        for (int i = start + 1; i < 24 * 3600; ++i) {
            string tmp = rev(i);
            if (foo[tmp[0] - '0'] && foo[tmp[1] - '0'] && foo[tmp[3] - '0'] && foo[tmp[4] - '0']
                && foo[tmp[6] - '0'] && foo[tmp[7] - '0']) {
                return tmp;
            }
        }

        for (int i = 0; i <= start; ++i) {
            string tmp = rev(i);
            if (foo[tmp[0] - '0'] && foo[tmp[1] - '0'] && foo[tmp[3] - '0'] && foo[tmp[4] - '0']
                && foo[tmp[6] - '0'] && foo[tmp[7] - '0']) {
                return tmp;
            }
        }
    }
};

int main() {
    Solution sol;
    int t;
    cin >> t;
    while (t--) {
        string time;
        cin >> time;
        cout << sol.nextClosestTime(time) << endl;
    }

    return 0;
}