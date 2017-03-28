#include <iostream>
using namespace std;

int solve(int n, int k) {
    if (n >= 2 * k) {
        int tmp = solve(n - n / k, k);
        if (tmp < n % k) {
            return (tmp + n - n % k) % n;
        } else {
            return (tmp + n - n % k + (tmp - n % k) / (k - 1)) % n;
        }
    } else {
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = (res + k) % i;
        }
        return res;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}