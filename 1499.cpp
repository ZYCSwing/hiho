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
int n, target;
int num[2][100000];

int main() {
    cin >> n;
    target = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num[0][i] >> num[1][i];
        target += num[0][i] + num[1][i];
    }
    target /= 2 * n;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        int diff0 = num[0][i] - target, diff1 = num[1][i] - target;
        if (diff0 + diff1 < 0) {
            if (diff0 < 0) {
                if (diff1 < 0) {
                    num[0][i + 1] += diff0;
                    num[1][i + 1] += diff1;
                } else {
                    num[0][i + 1] += diff0 + diff1;
                    res += diff1;
                }
            } else {
                num[1][i + 1] += diff0 + diff1;
                res += diff0;
            }
            res += abs(diff0 + diff1);
        } else if (diff0 + diff1 > 0) {
            if (diff0 < 0) {
                num[1][i + 1] += diff0 + diff1;
                res -= diff0;
            } else {
                if (diff1 < 0) {
                    num[0][i + 1] += diff0 + diff1;
                    res -= diff1;
                } else {
                    num[0][i + 1] += diff0;
                    num[1][i + 1] += diff1;
                }
            }
            res += diff0 + diff1;
        } else if (num[0][i] != num[1][i]) {
            res += abs(num[0][i] - num[1][i]) / 2;
        }
    }
    cout << res;

    return 0;
}