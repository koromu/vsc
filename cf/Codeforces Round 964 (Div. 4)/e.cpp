#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int pre[N];


void solve()
{
    int l, r ; cin >> l >> r;
    int ans = 0;

    int x = 0;
    ans = pre[l] - pre[l - 1];
    // cout << ans << "\n";
    ans += pre[r] - pre[l - 1];
    cout << ans << "\n";
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for(int i = 1 ; i <= N ; i ++)
    {
        int c = 0;
        int tmp = i;
        while(tmp)
        {
            tmp /= 3;
            c++;
        }
        pre[i] = pre[i - 1] + c;
    }
    cin >> t;
    while(t--)
        solve();

return 0;
}