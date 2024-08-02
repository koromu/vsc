#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int l, r, k; cin >> l >> r >> k;
    if(k == 0 && l == r && l != 1)
    {  
        cout << "YES\n";
        return;
    }
    if(l % 2 == 1)
    {
        // 如果l是奇数
        int ji = (r - l + 1 + 1) / 2;
        // cout << ji << "\n";
        if(k < ji)
        {
            cout << "NO\n"; 
        }
        else cout << "YES\n";
    }
    else 
    {
        int ji = (r - l + 1) / 2;
        // cout << ji << "\n";
        if(k < ji)
        {
            cout << "NO\n"; 
        }
        else cout << "YES\n";
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