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

vector<int> Rank;
int n;

int main() {
    cin >> n;
    Rank.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        Rank[num] = i;
    }
    // If i is ranked after i + 1, then it must be moved foreword, and immediately. So i numbers should be moved.
    for (int i = n - 1; i; --i) {
        if (Rank[i] > Rank[i + 1]) {
            cout << i;
            return 0;
        }
    }
    cout << 0;

    return 0;
}