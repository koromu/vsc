#include <bits/stdc++.h>
#define int long long
#define ft first
#define sd second
#define cn cout << "NO" << endl
#define cy cout << "YES" << endl
using namespace std;
const int mod = 1e9 + 7;

int n, k;

void solve()
{
    cin >> n >> k;
    priority_queue<int> dui;
    int maxv = -1e18;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        dui.push(x), maxv = max(maxv, x);
    }

    if (k == 1)
    {
        cout << maxv << endl;
        return;
    }

    int ans = maxv, cnt = 0;
    while (dui.size())
    {
        int t = dui.top();
        dui.pop();
        t /= k;
        cnt++;
        // cout << cnt << " " << 
        if (t < 0)
            dui.push(t);
        ans = min(ans, dui.top() + cnt);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}