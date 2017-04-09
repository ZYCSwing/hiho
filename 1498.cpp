/**
 * 初看像dp，但仔细想了发现只要剩下的工作在 2*Q 时间内无法完成，那么分裂出机器人就是有收益的，所以这种情况下全部分裂即可，无需dp
 */
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
ll n;
int q;

ll solve(ll num, ll job) {
    ll res = (job + num - 1) / num;
    if (2 * num * q >= job) {
        return res;
    }
    return q + solve(num << 1, job);
}

int main() {
    cin >> n >> q;
    cout << solve(1, n);

    return 0;
}