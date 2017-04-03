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
int p[21000];
//vector<int> p(21000, -1);
int n, m, res;
char mm[101][101];
//vector<vector<char>> mm(101, vector<char>(101));

int root(int x) {
    if (p[x] == -1) return x;
    if (x != p[x]) p[x] = root(p[x]);
    return p[x];
}

bool merge(int x1, int y1, int p1, int x2, int y2, int p2) {
    int a = ((x1 * m + y1) << 1) | p1;
    int b = ((x2 * m + y2) << 1) | p2;
    int ra = root(a), rb = root(b);
    if (ra != rb) {
        p[ra] = rb;
        return true;
    }
    return false;
}

int main() {
    memset(p, -1, sizeof(p));
    res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        getchar();
        for (int j = 0; j < m; ++j) {
            mm[i][j] = getchar();
            if (mm[i][j] == ' ') {
                merge(i, j, 0, i, j, 1);
                ++res;
            } else {
                res += 2;
            }
            if (i > 0 && merge(i, j, 0, i - 1, j, 1)) --res;
            if (j > 0) {
                int index1 = mm[i][j] == '/' ? 0 : 1;
                int index2 = mm[i][j - 1] == '/' ? 1 : 0;
                if (merge(i, j, index1, i, j - 1, index2)) --res;
            }
        }
    }
    cout << res << endl;

    return 0;
}