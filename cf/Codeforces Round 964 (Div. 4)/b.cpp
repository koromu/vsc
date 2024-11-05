#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int a[3], b[3];
    cin >> a[1] >> a[2] >> b[1] >> b[2];
    int ans = 0;
    if(a[1] > b[1])
    {
        if(a[2] > b[2])
        {
            ans ++;
        }
    }
    if(a[2] == b[2])
    {
        if(a[1] > b[1])
            ans ++;
    }
    if(a[1] == b[1])
    {
        if(a[2] > b[2])
            ans ++;
    }

    if(a[1] > b[2])
    {
        if(a[2] > b[1])
            ans ++;
    }

    if(a[1] == b[2])
    {
        if(a[2] > b[1])
            ans ++;
    }
    if(a[2] == b[1])
    {
        if(a[1] > b[2])
            ans ++;
    }
    
    cout << ans * 2 <<"\n";
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