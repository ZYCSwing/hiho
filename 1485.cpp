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

unordered_map<char, int> cnt;

int check() {
    if (cnt['h'] > 2 || cnt['i'] > 1 || cnt['o'] > 1) return 1;
    if (cnt['h'] == 2 && cnt['i'] == 1 && cnt['o'] == 1) return 0;
    return -1;
}

int main() {
    string str;
    cin >> str;
    int l = 0, r = 0, res = INT_MAX;
    while (r < str.length()) {
        while (r < str.length() && check() < 0) {
            if (str[r] == 'h' || str[r] == 'i' || str[r] == 'o'){
                cnt[str[r]]++;
            }
            r++;
        }
        while (check() > 0) {
            if (str[l] == 'h' || str[l] == 'i' || str[l] == 'o'){
                cnt[str[l]]--;
            }
            l++;
        }
        if (check() == 0) {
            res = min(res, r - l);
            if (str[l] == 'h' || str[l] == 'i' || str[l] == 'o'){
                cnt[str[l]]--;
            }
            ++l;
        }
    }

    cout << (res == INT_MAX ? -1 : res) << endl;

    return 0;
}