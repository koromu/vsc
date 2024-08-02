#include <bits\stdc++.h>
#define int long long
using namespace std;

const int N = 500010;
int n, l, r;
int w[N];


void solve()
{
    int n, k; cin >> n >> k;
    int ans = 0;
    if(k >= n)
    {
        ans ++;
        k -= n;
        n--;
    }
    while(k >= 2 * n && n)
    {
        ans += 2;
        k -= 2 * n;
        n--;
    }
    // 退出来的话就是n不够了, 或者n为0了
    if(k >= n && n)
    {
        ans += 1;
        k -= n;
        n--;
    }
    if(k) ans ++;
    // cout << n << endl;
    cout << ans << endl;
}

signed main()
{
    int _; cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}