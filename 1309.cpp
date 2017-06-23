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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n;
    vector<pair<int, int>> interval(n);
    for (int i = 0; i < n; ++i) {
        cin >> interval[i].first >> interval[i].second;
    }
    sort(interval.begin(), interval.end());
    for (int i = 0; i < n; ++i) {
        if (!pq.empty() && pq.top() <= interval[i].first) {
            pq.pop();
            pq.push(interval[i].second);
        } else {
            pq.push(interval[i].second);
        }
    }
    cout << pq.size();

    return 0;
}