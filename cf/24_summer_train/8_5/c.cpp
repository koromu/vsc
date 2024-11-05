#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int n, k;
    cin >> n >> k;
    string a; cin >> a;
    a = ' ' + a;
    int c0 = 0, c1 = 0;// 找0串, 如果找到一个1, 那么就看0串的长度, 能加的个数就是长度除k
    int ans = 0;
    bool f = false;
    for(int i = 1 ; i <= a.size() - 1; i ++)
    {
        if(a[i] == '0')
        {
            c0++;
        }
        else 
        {// 说明后面肯定是碰到1了
            if(f)
            {
                if(c0 > 2 * k)// 小于的话也不用看
                    ans += ((c0 - 2 * k - 1) / (k + 1)) + 1;
                c1++;// 两头都去掉了, 至少有一个
                c0 = 0;
                continue;
            }
            c1 ++;
            if(c0 > k)
                ans += ((c0 - k - 1) / (k + 1)) + 1;// 前面没有, 后面有
            // 小于的话不用看了
            c0 = 0;
            f = true;
        }
    }
    if(c1 == 0)
    {// 说明是没有1
        // if(c0 < k + 1) cout << "1\n";
        // else 
            cout << 1 + (c0 - 1) / (k + 1) << "\n";
        return;
    }
    if(c0)
    {
        // 前面一定有
        if(c0 > k)
            ans += (1 + ((c0 - k - 1) / (k + 1)));
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