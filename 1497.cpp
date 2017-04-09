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

unordered_map<int, int> rowCnt, colCnt, diag0, diag1;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        ++rowCnt[r];
        ++colCnt[c];
        ++diag0[r - c];
        ++diag1[r + c];
    }
    int res = 0;
    for (auto item : rowCnt) {
        res += item.second * (item.second - 1) / 2;
    }
    for (auto item : colCnt) {
        res += item.second * (item.second - 1) / 2;
    }
    for (auto item : diag0) {
        res += item.second * (item.second - 1) / 2;
    }
    for (auto item : diag1) {
        res += item.second * (item.second - 1) / 2;
    }
    cout << res;

    return 0;
}