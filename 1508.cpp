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

int n;
double r;
vector<pdd> points;

double dist(pdd& p1, pdd& p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

struct angle {
    double ang;
    bool isStart;
    angle(double a, bool flag): ang(a), isStart(flag){};
};

bool cmp(angle a, angle b) {
    return a.ang < b.ang;
}

int solve() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        vector<angle> tmp;
        for (int j = 0; j < n; ++j) {
            if (points[i].first == points[j].first && points[i].second == points[j].second) {
                ++cnt;
                continue;
            }
            double d = dist(points[i], points[j]);
            if (d >= 2 * r + eps) continue;
            double alpha = acos(d / (2 * r));
            double theta = atan2(points[j].second - points[i].second, points[j].first - points[i].first);
            tmp.push_back(angle{theta - alpha, true});
            tmp.push_back(angle{theta + alpha, false});
        }
        sort(begin(tmp), end(tmp), cmp);
        for (auto a : tmp) {
            if (a.isStart) {
                ++cnt;
                res = max(res, cnt);
            } else {
                --cnt;
            }
        }
    }
    return res;
}

int main() {
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        points.push_back(pdd(x, y));
    }
    cout << solve();

    return 0;
}