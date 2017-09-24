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
int n, m, q;

struct meeting {
    int s;
    int e;
} foo[MAXN], query[MAXN];

vector<int> allt, cnt;
int dp[MAXN << 2][20];

void init() {
    for (int i = 0; i < cnt.size(); ++i) {
        dp[i][0] = cnt[i];
    }

    for (int exp = 1; exp < 20; ++exp) {
        for (int start = 1; start + (1 << exp) - 1 < cnt.size(); ++start) {
            dp[start][exp] = max(dp[start][exp - 1], dp[start + (1 << (exp - 1))][exp - 1]);
        }
    }
}

int rmq(int l, int r) {
    int len = r - l + 1;
    int exp = 0, tmp = 1;
    while (tmp * 2 < len) {
        ++exp;
        tmp <<= 1;
    }
    return max(dp[l][exp], dp[r - tmp + 1][exp]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &foo[i].s, &foo[i].e);
        --foo[i].e;
        allt.pb(foo[i].s);
        allt.pb(foo[i].e);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &query[i].s, &query[i].e);
        --query[i].e;
        allt.pb(query[i].s);
        allt.pb(query[i].e);
    }

    sort(all(allt));
    allt.resize(distance(allt.begin(), unique(all(allt))));

    int sz = allt.size();
    cnt.assign(sz + 2, 0);
    for (int i = 0; i < n; ++i) {
        foo[i].s = lower_bound(all(allt), foo[i].s) - allt.begin() + 1;
        foo[i].e = lower_bound(all(allt), foo[i].e) - allt.begin() + 1;
        ++cnt[foo[i].s];
        --cnt[foo[i].e + 1];
    }

    for (int i = 1; i <= sz; ++i) {
        cnt[i] += cnt[i - 1];
    }

    init();

    for (int i = 0; i < q; ++i) {
        query[i].s = lower_bound(all(allt), query[i].s) - allt.begin() + 1;
        query[i].e = lower_bound(all(allt), query[i].e) - allt.begin() + 1;
        if (rmq(query[i].s, query[i].e) == m) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}