#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;

int w[N];

void solve()
{
    int n; cin >> n;
    int k = sqrt(n);
    // cout << k << "\n";
    int ans = 0;
    if(k * k == n)
    {
        // cout << 2 * (k - 1) << "\n";
        ans += 2 * (k - 1);
    }
    else if(k * k < n)
    {
        // 说明要增加一点点
        // int x = n - k * k;
        // cout << x << "\n";
        // int k2 = sqrt(x);
        // cout << k2 << endl;
        ans += 2 * (k - 1);
        int k1 = k, k2 = k;
        while(k1 * (k2 + 1) <= n)
        {
            ans ++;
            k2++;
            if(k1 < k2) swap(k1, k2);
        }
        // cout << k1 << " " << k2 << " " << k1 * k2 << " " << n - k1 * k2 << " " << ans << "\n";
        // 出来的时候k1和k2很接近, 而且也很接近n
        if(k1 * k2 < n)
        {
            if(k1 > (n - k1 * k2)) ans ++;
        }
    }

    cout << ans << "\n";
    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}