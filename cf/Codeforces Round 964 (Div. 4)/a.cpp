#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int n; cin >> n;
    vector<int> v1;
    while(n)
    {
        v1.push_back(n % 10);
        n /= 10;
    }
    int ans = 0;
    for(auto i : v1) ans += i;
    cout << ans << "\n"; 
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