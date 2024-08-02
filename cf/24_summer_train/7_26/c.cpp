#include <bits/stdc++.h>
// #define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

void solve()
{
    int n; cin >> n;
    int w[N];
    // 记录每一个数字出现的连续字段数量, 一个也算连续
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
    }
    map<int, int> mp;
    for(int i = 2 ; i <= n ; i ++)
    {
        if(w[i] == w[i - 1])
        {
            continue;
        }
        else 
        {
            // 这个数字的字段加1
            mp[w[i - 1]] ++;
        }
    }
    mp[w[n]]++;
    int res = 0x3f3f3f3f;
    int c = 0;
    for(auto i : mp) 
    {
        c++;
        int tmp = i.second;
        if(i.second != 1)
        {
            if(w[1] == i.first) tmp--;
            if(w[n] == i.first) tmp--;
            res = min(res, tmp + 1);
        }
        else 
        {
            if(w[1] == i.first || w[n] == i.first) 
                res = min(res, 1);
            else res = min(res, 2);
        }
        // cout << i.first << " " << i.second << endl;
    }
    if(c >= 2)
        cout << res << endl;
    else cout << 0 << endl;
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