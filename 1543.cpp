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

#define MAXN 1000000010
ll n;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll tmp = 2 * n;
        for (int k = sqrt(tmp - 1); k >= 1; --k) {
            if (tmp % k == 0) {
                ll foo = tmp / k;
                if (k % 2 != foo % 2) {
                    cout << k << endl;
                    break;
                }
            }
        }
    }

    return 0;
}