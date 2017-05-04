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

vector<int> diff;
bool check(vector<int> cnt) {
    sort(begin(cnt), end(cnt));
    return (cnt[1] - cnt[0] == diff[0] && cnt[2] - cnt[1] == diff[1])
           || (cnt[1] - cnt[0] == diff[1] && cnt[2] - cnt[1] == diff[0]);
}

int main() {
    for (int i = 0; i < 3; ++i) {
        int tmp;
        cin >> tmp;
        diff.push_back(tmp);
    }
    sort(begin(diff), end(diff));
    string str;
    cin >> str;
    if (diff[0] + diff[1] != diff[2]) {
        cout << str.length();
    } else {
        vector<int> cnt(3, 0);
        int res = 0, tmp = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == 'R') {
                ++cnt[0];
            } else if (str[i] == 'Y') {
                ++cnt[1];
            } else {
                ++cnt[2];
            }
            ++tmp;
            res = max(res, tmp);
            if (check(cnt)) {
                tmp = 0;
                cnt[0] = cnt[1] = cnt[2] = 0;
            }
        }
        cout << res;
    }

    return 0;
}