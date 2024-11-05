#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;

void solve()
{
    int k; cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    // a拿最大的b拿最大的, 最后a一定拿(n + 1) / 2个, b拿n / 2个 , 所以
    sort(w + 1, w + 1 + n);
    // for(int i = 1 ; i <= n ; i ++) cout << w[i] << " " ;
    // cout << "\n";
    int ans = 0;
    for(int i = n - 1 ; i >= 1 && k > 0 ; i -= 2)
    {
        // cout << "i : " <<  i << "\n";
        if(w[i] + k >= w[i + 1])
        {
            k -= (w[i + 1] - w[i]);
            w[i] = w[i + 1];
            // ans += (w[i + 1] - w[i] - k);
        }
        else 
        {
            w[i] += k;
            k = 0;
        }
    }
    
    // for(int i = n; i >= 1 && k >= 0; i -= 2)
    // {
    //     if(w[i] + k <= w[i + 1])
    //     {
    //         w[i] += k;// 如果大于了
    //     }
    // }


    for(int i = n, j = 1; i >= 1 ; i --, j ++)
    {
        // cout << w[j] << " ";
        if(j % 2 == 1)
        {
            ans += w[i];
        }
        else ans -= w[i];
    }

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