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
#define MAXN 55
int t;
int n, u;
struct Point {
    double x;
    double y;
}p[MAXN];

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double area(int a, int b, int c) {
    int dx1 = p[b].x - p[a].x, dy1 = p[b].y - p[a].y;
    int dx2 = p[c].x - p[a].x, dy2 = p[c].y - p[a].y;

    return 0.5 * abs(dx1 * dy2 - dx2 * dy1);
}

int main() {
    cin >> t;

    while (t--) {
        double maxA = 0, maxx, maxy;
        double minA = 1e30, minx, miny;
        cin >> n >> u;
        for (int i = 0; i < n; ++i) {
            cin >> p[i].x >> p[i].y;
        }
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                for (int c = b + 1; c < n; ++c) {
                    double tmp = area(a, b, c);
                    double tmpx = (p[a].x + p[b].x + p[c].x) / 3;
                    double tmpy = (p[a].y + p[b].y + p[c].y) / 3;
                    if (tmp > maxA) {
                        maxA = tmp;
                        maxx = tmpx;
                        maxy = tmpy;
                    } else if (abs(tmp - maxA) <= eps) {
                        if (tmpx > maxx) {
                            maxx = tmpx;
                            maxy = tmpy;
                        } else if (abs(tmpx - maxx) <= eps) {
                            if (tmpy > maxy) {
                                maxy = tmpy;
                            }
                        }
                    }

                    if (tmp > 0) {
                        if (tmp < minA) {
                            minA = tmp;
                            minx = tmpx;
                            miny = tmpy;
                        } else if (abs(tmp - minA) <= eps) {
                            if (tmpx < minx) {
                                minx = tmpx;
                                miny = tmpy;
                            } else if (abs(tmpx - minx) <= eps) {
                                if (tmpy < miny) {
                                    miny = tmpy;
                                }
                            }
                        }
                    }
                }
            }
        }

        printf("%.2lf\n", 0.5 * dist(minx, miny, maxx, maxy) / u);
    }

    return 0;
}