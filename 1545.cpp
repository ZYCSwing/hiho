#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <ctype.h>
using namespace std;

#define PI acos(-1.0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

#define eps 1e-8
#define mod 1000000007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

#define MAXN 100010

string res;
bool foo[MAXN];
unordered_map<int, vector<int>> mm;

int dfs(int ind) {
    int res = 0;
    for (int i : mm[ind]) {
        res ^= 1 + dfs(i);
    }
    return res;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        mm.clear();
        memset(foo, 0, sizeof(foo));
        for (int i = 0; i < n - 1; ++i) {
            int from, to;
            scanf("%d%d", &from, &to);
            mm[from].pb(to);
            foo[to] = true;
        }
        int root;
        for (int i = 1; i <= n; ++i) {
            if (!foo[i]) {
                root = i;
                break;
            }
        }
        int res0 = 0, res1 = 0;
        for (int i : mm[root]) {
            int tmp = dfs(i);
            res0 ^= (tmp + 1);
            res1 ^= tmp;
        }
        res.pb(res0 == 0 ? '0' : '1');
        res.pb(res1 == 0 ? '0' : '1');
    }
    cout << res;

    return 0;
}