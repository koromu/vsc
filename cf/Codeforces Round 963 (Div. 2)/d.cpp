#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7;
const int N = 200010;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    if (n <= k)
    {
        sort(v.begin(), v.end());
        cout << v[(n + 1) / 2 - 1] << '\n';
        return;
    }

    vector<int> dp(n, 0), b(n, 0);
    auto check = [&](int med) -> bool
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] >= med)
                b[i] = 1;
            else
                b[i] = -1;
        }

        dp[0] = b[0];
        for (int i = 1; i < n; i++)
        {
            if (i % k == 0)
                dp[i] = max(dp[i - k], b[i]);
            else
            {
                dp[i] = dp[i - 1] + b[i];
                if (i > k)
                    dp[i] = max(dp[i], dp[i - k]);
            }
        }

        return (dp[n - 1] > 0);
    };

    int ans = 0, l = 1, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}