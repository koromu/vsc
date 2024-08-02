#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <math.h>

#define int long long
using namespace std;


void solve() {
    int n; cin >> n;
    int k = (int)sqrtl(n);
    if(k * k < n)
    {
        k++;
    }
    if(k * (k - 1) < n || n % 2 == 1)
    {
        // 如果是属于k * k ~ k * (k + 1) * k, 就需要判断奇偶数
        cout << 2 * k + 1 << "\n";
    }
    else cout << 2 * k << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
