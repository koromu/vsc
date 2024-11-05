#include <bits/stdc++.h>
// using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7;
const int N = 200010;
int w[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    int sy[N] = {0};
    sy[1] = P;
    int minv = P;
    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            sy[i] = w[i] - w[i - 1];
        if (i != n)
        {
            sy[i] = min(w[i + 1] - w[i], sy[i]);
        }
        // cout << sy[i] << " ";
        minv = min(minv , sy[i]);
    }
    if(n == 2)
    {
        if(minv != 1)
        {
            cout << "YES\n";
        }
        else cout << "NO\n";
        return;
    }
    // cout << "\n";
    // if(n == 1)
    // {
    //     cout << "YES\n";
    //     return;
    // }
    // int minv = P;
    // for(int i = 2 ; i <= n ; i ++)
    // {
    //     minv = min(minv,w[i] - w[i - 1]);
    // }
    // cout << minv << "\n";
    // if(minv == 1)
    // {
    //     cout << "NO\n";
    // }
    // else
    // {
    //     if(n > 2)
    //     {
    //         cout << "NO\n";
    //     }
    //     else {
    //         if(minv % 2 == 0)
    //             cout << "YES\n";
    //         else cout << "NO\n";
    //     }
    // }
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if(sy[i] == minv)
        {
            tmp++;
            if (tmp == 2)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
