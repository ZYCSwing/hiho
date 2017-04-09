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
typedef vector<vector<int>> vvi;
//typedef vector<vector<ll>> vvll;

#define mod 1000000007

int n, r, c;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

vvi mul(vvi& a, vvi& b) {
    vvi res(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < a[0].size(); ++k) {
                // Attention! multiply 1L to avoid overflow
                res[i][j] = (res[i][j] + (1L * a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return res;
}

vvi myPow(vvi matrix, int nn) {
    vvi res(matrix.size(), vector<int>(matrix.size(), 0));
    for (int i = 0; i < matrix.size(); ++i) {
        res[i][i] = 1;
    }
    while (nn) {
        if (nn & 1) res = mul(res, matrix);
        matrix = mul(matrix, matrix);
        nn >>= 1;
    }
    return res;
}

vvi init() {
    vvi matrix(64, vector<int>(64, 0));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int from = i * 8 + j;
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < 8 && y >= 0 && y < 8) {
                    int to = x * 8 + y;
                    matrix[from][to] = 1;
                }
            }
        }
    }
    return matrix;
}

int main() {
    cin >> n >> r >> c;
    --r, --c;
    vvi foo(1, vector<int>(64));
    foo[0][8 * r + c] = 1;
    vvi matrix = init();
    matrix = myPow(matrix, n);
    foo = mul(foo, matrix);
    int res = 0;
    for (int i = 0; i < 64; ++i) {
        res += foo[0][i];
        res %= mod;
    }
    cout << res;

    return 0;
}