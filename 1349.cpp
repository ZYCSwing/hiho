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

ll mypow(int exp) {
    ll res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= 10;
    }
    return res;
}

int main() {
    vector<ll> foo;
    foo.push_back(0);
    ll cnt = 10;
    foo.push_back(10);
    while (cnt < 1e18) {
        cnt += 9 * mypow(foo.size() - 1) * (foo.size());
        foo.push_back(cnt);
    }

    ll n;
    cin >> n;
    ++n;

    int l = 1, r = 17;
    while (l < r) {
        int mid = (l + r) / 2;
        if (foo[mid] >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l == 1) {
        cout << n - 1;
    } else {
        n -= foo[l - 1];
        ll p = n / l, q = n % l;
        ll num = mypow(l - 1) + p;
        if (q == 0) {
            cout << (num - 1) % 10;
        } else {
            q = l - q;
            cout << num / mypow(q) % 10;
        }
    }

    return 0;
}