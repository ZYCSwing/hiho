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

int a, b, c, x, y;

double dist(double xx) {
    double yy = a * xx * xx + b * xx + c;
    return (x - xx) * (x - xx) + (y - yy) * (y - yy);
}

int main() {
    cin >> a >> b >> c >> x >> y;
    double l, r;
    if (x >= -0.5 * b / a) {
        l = -0.5 * b / a;
        r = 1e50;
    } else {
        l = -1e50;
        r = -0.5 * b / a;
    }
    while (r - l > eps) {
        double tmp = (r - l) / 3;
        double mid1 = l + tmp, mid2 = r - tmp;
        double res1 = dist(mid1), res2 = dist(mid2);
        if (res1 > res2) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    printf("%.3lf", sqrt(dist(l)));

    return 0;
}