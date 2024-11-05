#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;
int pre1[N], pre2[2 * N];

void solve()
{
    // 每一个数都要移动
    int n; cin >> n;

    int ans = 0;
    int pos = 1;
    for(int i = 1 ; i <= (n + 1) / 2 ; i ++)
    {
        ans += ((4 * pos - 4) * ( i - 1));
        pos += 2;
    }
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     pre1[i] = pre1[i - 1] + i;
    // }
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     pre2[i] = pre2[i - 1] + i + n;
    //     cout << pre2[i] << " ";
    // }
    // cout << "\n";
    // int ans = 0;
    // for(int i = 0 ; i <= n - 1 ; i ++)
    // {
    //     ans += (pre1[n] - pre1[i]);
    //     ans += (pre2[n] - pre2[i]);
    //     cout << pre2[n] - pre2[i] << "\n";
    // }
    cout << ans << "\n";

    cout << "\n";
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