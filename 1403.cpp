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

#define TOT 20010
#define MAX_N 100
int n, k;
int nums[TOT], sa[TOT], Rank[TOT], height[TOT];

int main() {
    cin >> n >> k;
    memset(nums, 0, sizeof(nums));
    vector<int> cntA(MAX_N + 1, 0);// 统计[1, 100]中每个数的个数
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        ++cntA[nums[i]];
    }
    // no need to continue
    if (k == 1) {
        cout << n << endl;
        return 0;
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

    for (int i = 1; i <= n; ++i) {
        Rank[sa[i]] = i;
    }

    // i is the index of nums
    for (int i = 1, j = 0; i <= n; ++i) {
        if (j) --j;
        while (nums[i + j] == nums[sa[Rank[i] - 1] + j]) ++j;
        height[Rank[i]] = j;
    }

    list<pii> foo;
    for (int i = 1; i < k; ++i) {
        while (!foo.empty() && foo.back().second >= height[i]) foo.pop_back();
        foo.push_back(pii(i, height[i]));
    }
    int res = foo.front().second;
    for (int i = k; i <= n; ++i) {
        if (foo.front().first <= i - k + 1) foo.pop_front();
        while (!foo.empty() && foo.back().second >= height[i]) foo.pop_back();
        foo.push_back(pii(i, height[i]));
        res = max(res, foo.front().second);
    }

    cout << res;

    return 0;
}