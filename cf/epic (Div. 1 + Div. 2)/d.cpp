#include <bits/stdc++.h>
// using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7;
const int N = 5050;
int a[N];
int dp[N];

void solve()
{
    int n;
    cin >> n;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    vector<int> vis;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= 5000; i++)
        if (a[i])
            vis.push_back(a[i]); // vis就是处理后的数组
    
    int m = vis.size();          // m就是背包问题中物品数量
    for (int i = 1; i < m; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (j >= vis[i])
            {
                dp[j + 1] = max(dp[j - vis[i]] + 1, dp[j + 1]);
            }
        }
    }
    int mx = 0;
    for (int i = 0; i <= m; i++)
    {
        mx = max(mx, dp[i]); // 找出dp数组中最大值,也就是Bob可以清零的蛋糕种类
    }
    cout << m - mx << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}