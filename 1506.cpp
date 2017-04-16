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
typedef vector<vector<int>> vvi;
//typedef vector<vector<ll>> vvll;

#define mod 1000000007
int n, m;
double p[1001];
double dp[1001][1001];
bool visited[1001][1001];

double solve(int tot, int up) {
    if (visited[tot][up]) return dp[tot][up];
    if (tot < up || up < 0) return 0.0;
    if (tot == 1) {
        return up == 1 ? p[1] : 1.0 - p[1];
    }
    visited[tot][up] = true;
    dp[tot][up] = solve(tot - 1, up - 1) * p[tot] + solve(tot - 1, up) * (1.0 - p[tot]);
    return dp[tot][up];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    memset(visited, 0, sizeof(visited));
    printf("%.6lf\n", solve(n, m));

    return 0;
}