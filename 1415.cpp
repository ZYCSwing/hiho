#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <numeric>
#include <cmath>
#include <memory.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<int>> vvi;

#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-8

vector<int> sa, ran, height;
string a, b;
int n, ind;

void cal() {
    sa.assign(n + 1, 0);
    ran.resize(n + 1);
    height.resize(n + 1);
    vector<int> cntA(27, 0);
    for (int i = 0; i < n; ++i) {
        ++cntA[a[i] - 'a'];
    }
    for (int i = 1; i < 27; ++i) {
        cntA[i] += cntA[i - 1];
    }
    for (int i = n; i; --i) {
        sa[cntA[a[i - 1] - 'a']--] = i;
    }
    ran[sa[1]] = 1;
    for (int i = 2; i <= n; ++i) {
        ran[sa[i]] = ran[sa[i - 1]];
        if (a[sa[i] - 1] != a[sa[i - 1] - 1]) ++ran[sa[i]];
    }

    for (int l = 1; ran[sa[n]] < n; l <<= 1) {
        vector<int> cntA(n + 1, 0), cntB(n + 1, 0);
        vector<int> A(n + 1), B(n + 1);
        for (int i = 1; i <= n; ++i) {
            ++cntA[A[i] = ran[i]];
            ++cntB[B[i] = (i + l <= n) ? ran[i + l] : 0];
        }
        for (int i = 1; i <= n; ++i) {
            cntA[i] += cntA[i - 1];
            cntB[i] += cntB[i - 1];
        }

        vector<int> tsa(n + 1, 0);
        for (int i = n; i; --i) {
            tsa[cntB[B[i]]--] = i;
        }
        for (int i = n; i; --i) {
            sa[cntA[A[tsa[i]]]--] = tsa[i];
        }

        ran[sa[1]] = 1;
        for (int i = 2; i <= n; ++i) {
            ran[sa[i]] = ran[sa[i - 1]];
            if (A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) ++ran[sa[i]];
        }
    }

    for (int i = 1, j = 0; i <= n; ++i) {
        if (j) --j;
        while (a[i + j - 1] == a[sa[ran[i] - 1] + j - 1]) ++j;
        height[ran[i]] = j;
    }
}

bool check(int m, int n) {
    return (m - ind) * (n - ind) < 0;
}

int main() {
    cin >> a >> b;
    ind = a.length() + 1;
    char ch = 'z' + 1;
    a = a + ch + b;
    n = a.length();

    cal();

    int res = 0;
    for (int i = 2; i <= n; ++i) {
        if (check(sa[i - 1], sa[i])) {
            res = max(res, height[i]);
        }
    }
    cout << res;

    return 0;
}