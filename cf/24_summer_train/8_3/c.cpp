#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int n; cin >> n;
    string a; cin >> a;
    a = ' ' + a;
    int c = 0;
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(a[i] == '(')
        {
            c++;
        }
        else
        {
            if(c)
            {
                c--;
            }
            else 
                ans ++;
        }
        
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