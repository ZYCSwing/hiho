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
#include <memory.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef long long ll;
#define N 110

int n, m, k;
int p[N], level[N], nums[N], dist[N][N], last[N];
bool isLeave[N];
vector<vector<int>> input;
vector<int> leaves;

void update(int child, int root) {
    for (int i = 1; i <= n; ++i) {
        if (i == root) continue;
        if (dist[child][i] > 0) {
            if (!isLeave[child] && dist[child][i] == level[i] - level[child]) {
                dist[i][root] = dist[root][i] = dist[child][i] + 1;
            } else {
                dist[i][root] = dist[root][i] = dist[child][i] - 1;
            }
        }
    }
}

void solve() {
    for (int i = m - 1; i > 0; --i) {
        for (int j = 0; j < input[i].size(); ++j) {
            int child = input[i][j];
            while (isLeave[input[i - 1][last[i - 1]]] || dist[child][input[i - 1][last[i - 1]]] > 1) ++last[i - 1];
            int root = input[i - 1][last[i - 1]];
            dist[child][root] = dist[root][child] = 1;
            p[child] = root;
            update(child, root);
        }
    }
}

int main() {
    memset(isLeave, 0, sizeof(isLeave));
    memset(dist, -1, sizeof(dist));
    memset(last, 0, sizeof(last));
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < m; ++i) {
        vector<int> row;
        for (int k = 0; k < nums[i]; ++k) {
            int id;
            cin >> id;
            level[id] = i;
            row.push_back(id);
        }
        input.push_back(row);
        if (i == 0) {
            p[row[0]] = 0;
        }
    }
    for (int i = 0; i < k; ++i) {
        int id;
        cin >> id;
        isLeave[id] = true;
        leaves.push_back(id);
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> dist[leaves[i]][leaves[j]];
        }
    }
    solve();

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << " ";
    }

    return 0;
}