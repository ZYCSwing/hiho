/**
 * 要判断是否满足第一个条件并不难，难点在判断是否一个块从外部可达
 * 直观的想法是每放入一个块，就可能隔开两个空间，可是"隔开"并不好判断，反倒是"合并"容易用并查集来实现
 * 所以就反着来，先将放好块后的各个空的区域分别合并，然后倒着移除每个块，移除的过程中先和周围的空白区域合并，
 * 再判断是否能合远端区域合并，若和远端区域还能合并，说明这个块原本接壤的空白区域和外面是隔开的，返回"No"即可
 */
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define TOT 102 * 102 * 102

vector<vector<int>> points;
int visited[102][102][102];
int cube[102][102][102];
int dx[6] = {1, 0, 0, 0, 0, -1};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, -1, 0, 0};
int p[TOT];

int root(int x) {
    if (x != p[x]) {
        p[x] = root(p[x]);
    }
    return p[x];
}

int getIndex(int x, int y, int z) {
    return x * 102 * 102 + y * 102 + z;
}

bool merge(int x, int y, int z, int u, int v, int w) {
    int a = getIndex(x, y, z);
    int b = getIndex(u, v, w);
    int ra = root(a);
    int rb = root(b);
    if (ra != rb) {
        p[ra] = rb;
        return true;
    }
    return false;
}

void solve() {
    for (int x = 0; x <= 101; ++x) {
        for (int y = 0; y <= 101; ++y) {
            for (int z = 0; z <= 101; ++z) {
                int index = getIndex(x, y, z);
                p[index] = index;
                if (cube[x][y][z]) visited[x][y][z] = 1;
            }
        }
    }

    for (int x = 0; x <= 101; ++x) {
        for (int y = 0; y <= 101; ++y) {
            for (int z = 1; z <= 101; ++z) {
                if (!cube[x][y][z]) {
                    for (int i = 0; i < 6; ++i) {
                        int xx = x + dx[i];
                        int yy = y + dy[i];
                        int zz = z + dz[i];
                        if (xx >= 0 && xx <= 101 && yy >= 0 && yy <= 101 && zz >= 1 && zz <= 101 && !cube[xx][yy][zz]) {
                            merge(x, y, z, xx, yy, zz);
                        }
                    }
                }
            }
        }
    }

    for (int i = points.size() - 1; i >= 0; --i) {
        int x = points[i][0];
        int y = points[i][1];
        int z = points[i][2];
        cube[x][y][z] = 0;
        for (int j = 0; j < 6; ++j) {
            int xx = x + dx[j];
            int yy = y + dy[j];
            int zz = z + dz[j];
            if (!cube[xx][yy][zz]) {
                merge(x, y, z, xx, yy, zz);
            }
        }
        if (merge(x, y, z, 101, 101, 101)) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        memset(visited, 0, sizeof(visited));
        memset(cube, 0, sizeof(cube));
        points.clear();
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            int x, y, z;
            cin >> x >> y >> z;
            if (!flag) continue;
            cube[x][y][z] = 1;
            if (z != 1) {
                int k;
                for (k = 0; k < 6; ++k) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    int zz = z + dz[k];
                    if (cube[xx][yy][zz]) break;
                }
                if (k == 6) {
                    flag = false;
                    continue;
                }
            }
            points.push_back({x, y, z});
        }
        if (!flag) {
            cout << "No" << endl;
            continue;
        }
        solve();
    }

    return 0;
}