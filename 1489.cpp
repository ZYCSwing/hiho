// 思想是得到n个的期望是得到n-1个的期望加上此时再拿一个的期望，由此可以递推得到结果，需要注意的是百分比右移7位或以上一定变0，所以要处理一下
// 否则会报WA，[del]虽然不知道这是为什么（感觉就算0多右移了几位应该也还是0才对。。。）[/del]因为右移31位以上的移位的位数会对32取余
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
int p, q, n;
double pp[101];
bool visited[101];

double calu(int init) {
    if (init == 100) return 1.0;
    if (visited[init]) return pp[init];
    visited[init] = true;
    double res = 0.01 * init + 0.01 * (100 - init) * (calu(min(100, init + q)) + 1);
    return pp[init] = res;
}

int main() {
    cin >> p >> q >> n;
    double res = 0.0;
    for (int i = 0; i < n; ++i) {
        res += calu(i < 7 ? p >> i : 0);
    }

    printf("%.2lf", res);

    return 0;
}
// 老方法 过了90% 会TLE
//#include <iostream>
//#include <vector>
//#include <map>
//#include <unordered_map>
//#include <set>
//#include <unordered_set>
//#include <stack>
//#include <queue>
//#include <algorithm>
//#include <list>
//#include <cstdio>
//#include <cstdlib>
//#include <climits>
//#include <memory.h>
//using namespace std;
//
//typedef pair<int, int> pii;
//typedef pair<double, int> pdi;
//typedef long long ll;
//#define N 1000010
//int p, q, n;
//float dp[110][N];
//bool visited[110][N];
//vector<int> foo;
//
//float solve(int init, int last) {
//    if (last == 0) {
//        return 0;
//    }
//    if (visited[init][last]) return dp[init][last];
//    visited[init][last] = true;
//    float res;
//    if (init == 100) {
//        res = 1.0 + solve(foo[min(n - last, (int)foo.size() - 1)], last - 1);
//    } else {
//        res = 1.0 + 0.01 * init * solve(foo[min(n - last, (int)foo.size() - 1)], last - 1) + 0.01 * (100 - init) * solve(min(100, init + q), last);
//    }
//    return dp[init][last] = res;
//}
//
//int main() {
//    cin >> p >> q >> n;
//    memset(visited, 0, sizeof(visited));
//    if (p == 0) {
//        foo.push_back(0);
//    } else {
//        int tmp = p;
//        while (tmp > 0) {
//            tmp /= 2;
//            foo.push_back(tmp);
//        }
//    }
//    printf("%.2f", solve(p, n));
//
//    return 0;
//}
