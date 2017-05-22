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

int main() {
    int n, pp, pn, np;
    cin >> n;
    pp = pn = np = 0;
    while (n--) {
        char ch1, ch2;
        cin >> ch1 >> ch2;
        if (ch1 == '+') {
            if (ch2 == '-') {
                ++pn;
            } else {
                ++pp;
            }
        } else if (ch2 == '+') {
            ++np;
        }
    }
    double precision = 1.0 * pp / (np + pp);
    double recall = 1.0 * pp / (pn + pp);
    double res = 2.0 / (1 / precision + 1 / recall);
    printf("%.2lf%%", 100 * res);

    return 0;
}