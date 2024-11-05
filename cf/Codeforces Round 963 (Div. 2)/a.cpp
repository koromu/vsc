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
    int ca = 0, cb = 0, cc = 0, cd = 0;
    for(int i = 1 ; i <= a.size() - 1 ; i ++)
    {
        // n个abcd
        if(a[i] == 'A') ca ++;
        else if(a[i] == 'B') cb ++;
        else if(a[i] == 'C') cc ++;
        else if(a[i] == 'D') cd ++;
    }
    // cout << ca << " " << cb << " " << cc << " " << cd << '\n';
    cout << min(ca, n) + min(cb, n) + min(cc, n) + min(cd, n) << '\n';
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