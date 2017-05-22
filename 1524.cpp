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

int n;
vector<int> nums;

int lowbit(int x) {return x & -x;}

void add(int x) {
    while (x <= n) {
        ++nums[x];
        x += lowbit(x);
    }
}

ll sum(int x) {
    ll res = 0;
    while (x) {
        res += nums[x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    cin >> n;
    nums.assign(n + 1, 0);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        res += (i - sum(num));
        add(num);
    }
    cout << res;

    return 0;
}