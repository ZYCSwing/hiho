#include <iostream>
#include <vector>
using namespace std;

int gao(vector<int>& paras, int& w, int& h, int font) {
    int tot = 0;
    int nrow = w / font, ncol = h / font;
    for (int i : paras) {
        tot += (i + nrow - 1) / nrow;
    }
    return (tot + ncol - 1) / ncol;
}

int main() {
    int t, n, p, w, h;

    cin >> t;
    while (t--) {
        cin >> n >> p >> w >> h;
        vector<int> paras(n);
        for (int i = 0; i < n; ++i) {
            cin >> paras[i];
        }
        int l = 1, r = min(w, h);
        while (l < r) {
            int mid = r - (r - l) / 2;
            if (gao(paras, w, h, mid) <= p) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << endl;
    }

    return 0;
}