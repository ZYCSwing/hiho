#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <numeric>
#include <cmath>
#include <memory.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<int>> vvi;

#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-8

int n;
list<pii> Inc, Dec, nums;

void insert(pii a) {
    nums.push_back(a);
    while (!Inc.empty() && Inc.back().second >= a.second) Inc.pop_back();
    Inc.push_back(a);
    while (!Dec.empty() && Dec.back().second <= a.second) Dec.pop_back();
    Dec.push_back(a);
}

void remove(int time) {
    while (!nums.empty() && nums.front().first <= time) nums.pop_front();
    while (!Inc.empty() && Inc.front().first <= time) Inc.pop_front();
    while (!Dec.empty() && Dec.front().first <= time) Dec.pop_front();
}

void query() {
    cout << Dec.front().second << " " << Inc.front().second << " " << nums.back().second << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'P') {
            int time, price;
            cin >> time >> price;
            insert({time, price});
        } else if (op == 'Q') {
            query();
        } else {
            int time;
            cin >> time;
            remove(time);
        }
    }

    return 0;
}