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

#define TOT 100010
#define MAX_N 1000
int n;
int nums[TOT], sa[TOT], Rank[TOT], height[TOT];

bool solve(int k) {
    int lower = n, upper = 1;
    for (int i = 1; i <= n; ++i) {
        if (height[i] >= k) {
            lower = min(lower, sa[i]);
            upper = max(upper, sa[i]);
            if (upper - lower >= k) return true;
        } else {
            lower = upper = sa[i];
        }
    }
    return false;
}

int main() {
    cin >> n;
    memset(nums, 0, sizeof(nums));
    vector<int> cntA(MAX_N + 1, 0);// 统计[1, 100]中每个数的个数
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        ++cntA[nums[i]];
    }
    for (int i = 1; i <= MAX_N; ++i) {
        cntA[i] += cntA[i - 1];
    }
    for (int i = n; i ; --i) {
        sa[cntA[nums[i]]--] = i;
    }
    Rank[sa[1]] = 1;
    for (int i = 2; i <= n; ++i) {
        Rank[sa[i]] = Rank[sa[i - 1]];
        if (nums[sa[i]] != nums[sa[i - 1]]) ++Rank[sa[i]];
    }

    for (int l = 1; Rank[sa[n]] < n; l <<= 1) {
        // cntA统计第一维排名的分布，cntB统计第二维
        vector<int> cntA(n + 1, 0), cntB(n + 1, 0), A(n + 1), B(n + 1), tsa(n + 1);
        for (int i = 1; i <= n; ++i) {
            ++cntA[A[i] = Rank[i]];
            ++cntB[B[i] = (i + l <= n) ? Rank[i + l] : 0];
        }
        for (int i = 1; i <= n; ++i) {
            cntA[i] += cntA[i - 1];
            cntB[i] += cntB[i - 1];
        }
        // i is the index of nums
        for (int i = n; i; --i) {
            tsa[cntB[B[i]]--] = i;
        }
        // i is the index of tsa —— the Rank
        for (int i = n; i; --i) {
            sa[cntA[A[tsa[i]]]--] = tsa[i];
        }
        Rank[sa[1]] = 1;
        // i is the index of sa —— the Rank
        for (int i = 2; i <= n; ++i) {
            Rank[sa[i]] = Rank[sa[i - 1]];
            if (A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) ++Rank[sa[i]];
        }
    }

    // no need
//    for (int i = 1; i <= n; ++i) {
//        Rank[sa[i]] = i;
//    }

    // i is the index of nums
    for (int i = 1, j = 0; i <= n; ++i) {
        if (j) --j;
        while (nums[i + j] == nums[sa[Rank[i] - 1] + j]) ++j;
        height[Rank[i]] = j;
    }

    int l = 0, r = n / 2;
    while (l < r) {
        int mid = r - (r - l) / 2;
        if (solve(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;

    return 0;
}