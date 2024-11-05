#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;
int pre[N] = {0};
int dp[N][2] = {0};

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = ' ' + s;
    int c0 = 0;
    int ans = 0;
    for(int i = 0 ; i <= n ; i ++)
    {
        dp[i][0] = dp[i][1] = P;
    }
    for(int i = 1; i <= n ; i ++)
    {
        pre[i] = pre[i - 1] + (s[i] == '1');
        // cout << pre[i] << " ";
    }
    // cout << "\n";
    // 然后dp[i][1 / 0]表示第i位是1 / 不是1的情况
    // 如果这位是1, 那么要增加的操作次数就是dp[i][1] = min(dp[i][1], dp[i - k][1] + (pre[i] - pre[i - k - 1]) s[i] == '0' );
    // 如果这位是0, 那么要增加的操作次数就是dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + s[i] == '1);
    for(int i = 1 ; i <= n ; i ++)
    {
        dp[i][1] = min(dp[i][1], dp[i - k][1] + (pre[i] - pre[i - k - 1]) + (s[i] == '0') );
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + (s[i] == '1'));
    }
    
    cout << min(dp[n][1], dp[n][0]) << "\n";
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