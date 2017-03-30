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
int p[1000000];
bool valid[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int root(int x) {
    if (p[x] == -1) return x;
    if (x != p[x]) {
        p[x] = root(p[x]);
    }
    return p[x];
}

int getIndex(int x, int y) {
    return x * 1000 + y;
}

bool merge(int x1, int y1, int x2, int y2) {
    int r1 = root(getIndex(x1, y1));
    int r2 = root(getIndex(x2, y2));
    if (r1 != r2) {
        p[r1] = r2;
        return true;
    }
    return false;
}

int main() {
    int n, cnt = 0, length = 0;
    cin >> n;
    memset(p, -1, sizeof(p));
    memset(valid, 0, sizeof(valid));
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        valid[x][y] = 1;
        cnt++;
        length += 4;
        for (int j = 0; j < 4; ++j) {
            int xx = x + dx[j];
            int yy = y + dy[j];
            if (xx < 0 || xx >= 1000 || yy < 0 || yy >= 1000 || !valid[xx][yy]) continue;
            length -= 2;
            if (merge(x, y, xx, yy)) {
                cnt--;
            }
        }
        cout << cnt << " " << i + 1 << " " << length << endl;
    }

    return 0;
}