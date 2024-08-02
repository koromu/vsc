#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 45;

int n, x, y;

vector<int> v1;
string mp[2];

void solve()
{
    cin >> n;
    for(int i = 0 ; i < 2 ; i ++) cin >> mp[i];
    int ans = 0;
    for(int j = 0 ; j < n ; j ++)
    {
        if(mp[0][j] == 'x' && mp[0][j + 1] == '.' && mp[0][j + 2] == 'x' && mp[1][j + 1] == '.' && mp[1][j] == '.' && mp[1][j + 2] == '.') 
        {
            ans ++;
        }
        if(mp[1][j] == 'x' && mp[1][j + 1] == '.' && mp[1][j + 2] == 'x' && mp[0][j + 1] == '.' && mp[0][j] == '.' && mp[0][j + 2] == '.') 
        {
            ans ++;
        }
    }
    cout << ans << "\n";

    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 0;
    cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}