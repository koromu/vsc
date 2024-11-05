#include <bits/stdc++.h>
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

int w[N];

void solve()
{
    // int maxv = 0;
    // int n, k; cin >> n >> k;
    // for(int i = 1 ; i <= n ; i ++) {
    //     cin >> w[i];
    //     maxv = max(maxv, w[i]);
    // }
    // int m1 = 1e9 +7, m2 = 1e9 + 7;
    // int m3 = 0, m4 = 0;
    // int c1 = 0, c2 = 0;
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     cout << (((maxv - w[i]) / k)) % 2 << " ";// 得到了所有的灯此时的状态
    //     if((((maxv - w[i]) / k)) % 2)
    //     {
    //         m1 = min(m1, (k - ((maxv - w[i]) % k)));
    //         m3 = max(m3, (k - ((maxv - w[i]) % k)));
    //         c1 ++;
    //     }
    //     else 
    //     {
    //         m2 = min(m2, k - ((maxv - w[i]) % k));
    //         m4 = max(m4, k - ((maxv - w[i]) % k));
    //         c2++;
    //     }
    // }
    // cout << "\n";
    // if(c1 && c2)
    // {
    //     if((m1 >= m2 && m1 <= m4) || (m2 >= m1 && m2 <= m3)) cout << "-1\n";
    //     else
    //     {
    //         cout << maxv + min(m1, m2) << "\n";
    //     }
    // }
    // else cout << maxv << "\n";
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     cout << (k - ((maxv - w[i]) % k)) << " ";// 得到了所有的灯此时的状态
    // }

    int n, k;
    cin >> n >> k;
    int maxv = 0;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> w[i];
        maxv = max(maxv, w[i]);
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        int t1 = (maxv - w[i]) / (2 * k) * (2 * k);
        w[i] += t1;
        if(abs(w[i] - maxv) > abs(2 * k + w[i] - maxv)) w[i] += 2 * k;
        // cout << w[i] << " "; 
    }

    // cout << "\n";
    sort(w + 1, w + n + 1);
    
    if(w[n] - w[1] >= k) cout << "-1\n";
    else
    {
        // cout << max(w[n], w[1] + k - w[1] % k - 1) << "\n";
        cout << w[n] << "\n";
    }
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