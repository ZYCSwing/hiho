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
int n;
unordered_map<int, int> reminder;

int main() {
    cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        if (flag) continue;
        if (b == 1) {
            cout << i;
            flag = true;
        } else if (reminder.find(b) != reminder.end()) {
            cout << reminder[b] << " " << i;
            flag = true;
        } else {
            reminder[b] = i;
        }
    }

    return 0;
}