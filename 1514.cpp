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
#include <cmath>
#include <memory.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<int>> vvi;
//typedef vector<vector<ll>> vvll;
#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-8
vector<pii> pos;
int n, m, l;

int calu(int a, int b, int c) {
    return abs(a - b) + abs(a - c) + abs(b - c);
}

int main() {
    cin >> n >> m >> l;
    vector<int> a(n), b(m), c(l);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0; i < l; ++i) cin >> c[i];
    vector<int> indexs(3, 0);
    int res = INT_MAX;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    sort(begin(c), end(c));
    while (indexs[0] < n && indexs[1] < m && indexs[2] < l) {
        if (a[indexs[0]] <= b[indexs[1]] && a[indexs[0]] <= c[indexs[2]]) {
            while (indexs[0] < n && a[indexs[0]] <= b[indexs[1]] && a[indexs[0]] <= c[indexs[2]]) {
                res = min(res, calu(a[indexs[0]++], b[indexs[1]], c[indexs[2]]));
            }
        } else if (b[indexs[1]] <= a[indexs[0]] && b[indexs[1]] <= c[indexs[2]]) {
            while (indexs[1] < m && b[indexs[1]] <= a[indexs[0]] && b[indexs[1]] <= c[indexs[2]]) {
                res = min(res, calu(a[indexs[0]], b[indexs[1]++], c[indexs[2]]));
            }
        } else {
            while (indexs[2] < l && c[indexs[2]] <= a[indexs[0]] && c[indexs[2]] <= b[indexs[1]]) {
                res = min(res, calu(a[indexs[0]], b[indexs[1]], c[indexs[2]++]));
            }
        }
    }
    cout << res;

    return 0;
}