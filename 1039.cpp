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

int solve(string str) {
    string foo = str;
    int diff;
    do {
        diff = 0;
        auto it = begin(foo);
        while (it != end(foo)) {
            if (next(it) == end(foo) || *it != *next(it)) {
                ++it;
            } else {
                while (next(it) != end(foo) && *it == *next(it)) {
                    it = foo.erase(it);
                    ++diff;
                }
                it = foo.erase(it);
                ++diff;
            }
        }
    } while (diff);

    return foo.length();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int res = 101;
        for (int i = 0; i <= str.length(); ++i) {
            for (char j = 'A'; j <= 'C'; ++j) {
                res = min(res, solve(str.substr(0, i) + j + str.substr(i)));
            }
        }
        cout << str.length() + 1 - res << endl;
    }

    return 0;
}