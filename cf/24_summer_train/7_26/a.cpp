#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1e6 + 10;

void solve()
{
    int n; cin >> n;
    for(int i = 2 ; i <= n ; i ++)
    {
        cout << i << " ";
    }
    cout << 1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
     cin >> _;
    while(_--)
    {
        solve();
    }
}