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

int gao(string s) {
    int len = s.length();
    vector<char> str((len + 1) << 1);
    vector<int> p((len + 1) << 1, 0);

    str[0] = '$';
    str[1] = '#';
    for (int i = 0; i < len; ++i) {
        str[(i + 1) << 1] = s[i];
        str[(i + 1) << 1 | 1] = '#';
    }

    int id = 0;
    for (int i = 1; i < 2 * len + 2; ++i) {
        if (id + p[id] > i) {
            p[i] = min(p[2 * id - i], id + p[id] - i);
        } else {
            p[i] = 1;
        }
        while (str[i + p[i]] == str[i - p[i]]) ++p[i];
        if (i + p[i] > id + p[id]) {
            id = i;
        }
    }
    int res = 0;
    for (int i = 1; i < 2 * len + 2; ++i) {
        res = max(res, p[i] - 1);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << gao(s) << endl;
    }

    return 0;
}