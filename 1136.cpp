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

int n, m;
vector<int> start;
unordered_map<int, unordered_set<int>> input;
vector<unordered_multiset<int>> output;
vector<int> cnt;

void dfs(int signal) {
    if (input.find(signal) != input.end()) {
        for (int index : input[signal]) {
            ++cnt[index];
            for (int out : output[index]) {
                dfs(out);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%d%d", &n, &m);
        start.resize(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &start[i]);
        }
        output.resize(n);
        cnt.resize(n);
        for (int i = 0; i < n; ++i) {
            int s, k;
            scanf("%d%d", &s, &k);
            input[s].insert(i);
            for (int j = 0; j < k; ++j) {
                int signal;
                scanf("%d", &signal);
                output[i].insert(signal);
            }
        }
        for (int signal : start) {
            dfs(signal);
        }
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", cnt[i]);
        }
        printf("\n");
        start.clear();
        input.clear();
        output.clear();
        cnt.clear();
    }

    return 0;
}