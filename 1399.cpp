#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0, tmp;

    while (n--) {
        cin >> tmp;
        if (tmp % 2) {
            ++res;
        } else {
            --res;
        }
    }
    cout << abs(res);

    return 0;
}