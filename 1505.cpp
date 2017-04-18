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
int n;
vector<int> a;
unordered_map<int, int> cnt, sum;

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        for (int j = 0; j < i; ++j) {
            ++sum[a[j] + a[i]];
        }
    }
    ll res = 0;
    for (auto item : sum) {
        res += 1L * item.second * (item.second - 1) / 2;
    }
    for (int i = 0; i < n; ++i) {
        for (auto item : cnt) {
            if (a[i] == item.first) {
                res -= 1L * (item.second - 1) * (item.second - 2) / 2;
            } else {
                res -= 1L * item.second * (item.second - 1) / 2;
            }
        }
    }
    cout << res * 2;

    return 0;
}