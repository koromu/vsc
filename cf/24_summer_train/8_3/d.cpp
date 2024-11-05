#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];

void solve()
{
    i64 n, k;
    cin >> n >> k;
    map<i64, i64> mp;
    bool f = false;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
        // cout << (((k - w[i]) % k + k) % k) << " ";
        if(w[i] % k)// 得有值才行
        {
            mp[(((k - w[i]) % k + k) % k)]++;
        }
    }
    // cout << "\n";
    i64 cmax = 0;
    i64 maxv = 1e9 + 10;

    // 对于最多的余数
    for(auto i : mp)
    {
        // cout << i.first << " " << i.second << "\n";
        // 找到最大的那个次数
        if(i.second > cmax)
        {
            cmax = i.second;
            maxv = i.first;
        }
        else if(i.second == cmax)
        {
            maxv = max(maxv, i.first);
        }
    }

    // cout << maxv << " " << cmax << "\n";
    if(maxv == 1e9 + 10)
    {
        cout << 0 << "\n";
        return;
    }
    // if(cmax == 1)
    // {
    //     cout << maxv << "\n";
    //     return;
    // }
    cout << (cmax - 1) * k + maxv + 1 << "\n";
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