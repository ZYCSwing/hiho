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

string trans_2c(string str) {
    string res;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != '_') {
            res.push_back(str[i]);
        } else {
            res.push_back(str[++i] - 'a' + 'A');
        }
    }
    return res;
}

string transc2_(string str) {
    string res;
    for (int i = 0; i < str.length(); ++i) {
        if (isupper(str[i])) {
            res.push_back('_');
            res.push_back(str[i] - 'A' + 'a');
        } else {
            res.push_back(str[i]);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if (str.find('_') != string::npos) {
            cout << trans_2c(str) << endl;
        } else {
            cout << transc2_(str) << endl;
        }
    }

    return 0;
}