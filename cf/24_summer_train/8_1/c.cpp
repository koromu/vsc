#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = (d - b);
    int tmp = 0;
    if(ans < 0) cout << "-1\n";
    else 
    {
        tmp = ((d - b) + (a - c));
        if(tmp < 0)
            cout << "-1\n";
        else cout << ans + tmp << "\n";
    }
    // cout << ans << " " << tmp << "\n";
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