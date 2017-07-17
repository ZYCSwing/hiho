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

ll a, b, p;

ll power_mod(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % p;
        base = base * base % p;
        exp >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return power_mod(x, p - 2);
}

int main() {
    cin >> a >> b >> p;

    cout << a * inv(b) % p;

    return 0;
}