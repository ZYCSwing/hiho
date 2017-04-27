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
#define N 100000

int n, m, q;
//int p[N + 1], score[N + 1];
vector<int> p(N + 1), score(N + 1);

int root(int x) {
    if (x != p[x]) {
        int tmp = p[x];
        p[x] = root(p[x]);
        score[x] += score[tmp];
    }
    return p[x];
}

int main() {
    for (int i = 1; i <= N; ++i) {
        p[i] = i;
        score[i] = 0;
    }
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int x, y, s;
        cin >> x >> y >> s;
        int rootx = root(x), rooty = root(y);
        if (rootx != rooty) {
            score[rootx] += s - (score[x] - score[y]);
            p[rootx] = rooty;
        }
    }
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if (root(x) != root(y)) {
            cout << -1 << endl;
        } else {
            cout << score[x] - score[y] << endl;
        }
    }

    return 0;
}