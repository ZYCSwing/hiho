#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    vector<bool> flag(n + 1, true);
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (flag[nums[i]]) {
            int j = i, cnt = 0;
            while (flag[nums[j]]) {
                ++cnt;
                flag[nums[j]] = false;
                j = nums[j];
            }
            res = max(res, cnt);
        }
    }
    cout << res;

    return 0;
}