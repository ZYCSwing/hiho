#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define UPPER 200
int n, m;
char matrix[101][101];
int dp[101][101][2];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int solve(int x, int y, int dir) {
    if (x >= n || y >= m) return UPPER;
    if (dp[x][y][dir] != -1) return dp[x][y][dir];
    if (x == n - 1 && y == m - 1) return 0;
    int res = matrix[x][y] == '.' ? 0 : 1;
    // go through
    int foo = solve(x + dx[dir], y + dy[dir], dir);
    // try another direction
    int bar;
    if (x + dx[dir] < n && y + dy[dir] < m && matrix[x + dx[dir]][y + dy[dir]] == '.') {
        bar = 1;
    } else {
        bar = 0;
    }
    bar += solve(x + dx[1 - dir], y + dy[1 - dir], 1 - dir);
    res += min(foo, bar);

    return dp[x][y][dir] = res;
}

int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            cin >> matrix[row][col];
        }
    }
    cout << solve(0, 0, 1);

    return 0;
}