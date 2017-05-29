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

bool solve(map<pii, vector<pii>>& edges) {
    if (edges.size() != 4) return false;
    for (auto item : edges) {
        if (item.second.size() != 2) return false;
        int dx1 = item.second[0].first - item.first.first, dy1 = item.second[0].second - item.first.second;
        int dx2 = item.second[1].first - item.first.first, dy2 = item.second[1].second - item.first.second;
        if (dx1 * dx2 + dy1 * dy2 != 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        map<pii, vector<pii>> edges;
        for (int i = 0; i < 4; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            edges[{x1, y1}].push_back({x2, y2});
            edges[{x2, y2}].push_back({x1, y1});
        }
        cout << (solve(edges) ? "YES" : "NO") << endl;
    }

    return 0;
}