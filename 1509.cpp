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
vector<ll> nums;
unordered_map<int, bool> foo;

bool gao(ll& a, ll& b) {
    for (int i = 59; i >= 0; --i) {
        ll mask = 1L << i;
        if ((a & mask) != (b & mask)) {
            if ((a & mask) < (b & mask)) {
                if (foo.find(i) != foo.end() && foo[i] == 1) return false;
                foo[i] = 0;
            } else {
                if (foo.find(i) != foo.end() && foo[i] == 0) return false;
                foo[i] = 1;
            }
            break;
        }
    }
    return true;
}

int main() {
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    for (int i = 0; i < n - 1; ++i) {
        if (!gao(nums[i], nums[i + 1])) {
            cout << 0;
            return 0;
        }
    }
    cout << (1L << (60 - foo.size()));

    return 0;
}