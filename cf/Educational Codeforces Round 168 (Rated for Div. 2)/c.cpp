#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;

int n, x, y;

vector<int> v1;
void solve()
{
    bool st[N] = {false};
    cin >> n;
    string a; cin >> a;
    a = ' ' + a;
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(a[i] == '(')
        {
            ans ++;
            st[i + 1] = true;
        }
    }
    
    int pos = 0;
    for(int i = n ; i >= 1 ; i --)
    {
        if(a[i] == ')')
        {
            pos = i;
            break;
        }
    }
    if(pos == 0)
    {
        cout << ans << "\n";
        return;
    }

    for(int i = pos ; i >= 1 ; i --)
    {
        if(!st[i] && a[i] == '_')
        {
            // cout << pos << " " << i << "\n";
            ans += (pos - i);
            for(int j = i ; j >= 1 ; j --)
            {
                if(a[j] == ')')
                {
                    pos = j;
                    i = pos + 1;
                    break;
                }
            }
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