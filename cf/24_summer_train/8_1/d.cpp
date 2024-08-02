#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int n, m; cin >> n >> m ;
    if(n == 1 && m == 1)
    {
        cout << 0 << "\n";
        return;
    }
    int ans = n + m - 1;
    ans += min(n, m);
    cout << ans - 1 << '\n';
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