#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int x, y, n; cin >> x >> y >> n;
    // cout << (n / x) * x << " " << (n / x) * x - y <<  "\n";
    // cout << 12339 % x << " " << 12336 % x << " \n";
    if(n / x * x + y <= n)
    {
        cout << n / x * x + y << "\n";
    }
    else if(n / x * x - (x - y) <= n)
    {
        cout << n / x * x - (x - y) << "\n";
    }
    else cout << n / x * x - y << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();

return 0;
}