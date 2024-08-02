#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    string s; cin >> s;
    s = ' ' + s;
    int c3, c4, c5, cu;
    int lun = 0;
    for(int i = 1 ; i <= s.size() - 1 ; i ++)
    {
        if(s[i] == '3') c3 ++;
        else if(s[i] == '4') c4 ++;
        else if(s[i] == '5') c5 ++;
        else cu ++;
        lun = i / 10;// 0轮至少有一个4, 9轮至少有一个5, 至多有
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