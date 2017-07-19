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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

#define MAXN 100010

int n;
int a[MAXN];

unordered_map<ll, vector<int>> indexs;

int res = 0;

void solve(ll s1, ll s2) {
    for (int i = 0; i < indexs[s1].size(); ++i) {
        int ind1 = indexs[s1][i];
        auto foo = upper_bound(all(indexs[s2]), ind1);
        if (foo == indexs[s2].end()) continue;
        res += distance(foo, indexs[s2].back() < n - 1 ? indexs[s2].end() : prev(indexs[s2].end()));
    }
}

int main() {
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        indexs[sum].pb(i);
    }

    ll tmp = llabs(sum);
    ll sub = tmp / 3;
    ll differ = sub + 1;
    if (sum < 0) {
        sub = -sub;
        differ = -differ;
    }
    if (tmp % 3 == 0) {
        solve(sub, 2 * sub);
    } else if (tmp % 3 == 1) {
        solve(sub, 2 * sub);
        solve(sub, sub + differ);
        solve(differ, sub + differ);
    } else {
        solve(sub, sub + differ);
        solve(differ, sub + differ);
        solve(differ, 2 * differ);
    }

    cout << res;

    return 0;
}