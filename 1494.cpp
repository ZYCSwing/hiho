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
int foo[100000001], res;

int main() {
    int n;
    cin >> n;
    res = 0;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        int sum = 0;
        for (int j = 0; j < c; ++j) {
            int tmp;
            cin >> tmp;
            if (j < c - 1) {
                sum += tmp;
                foo[sum]++;
                if (foo[sum] > res) res = foo[sum];
            }
        }
    }
    cout << n - res;

    return 0;
}