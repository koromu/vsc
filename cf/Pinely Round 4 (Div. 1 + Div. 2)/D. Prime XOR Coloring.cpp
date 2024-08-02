#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int n; cin >> n;
    // 四的倍数真的是最小的了， 不能再小了
    // 二的倍数还是有可能得到2, 三的倍数有可能得到3, 都是素数
    // cout << (1 ^ 2) << "\n";
    // cout << (2 ^ 2) << "\n";
    if(n == 1) cout << 1 << "\n";
    else if(n == 2) cout << 2 << "\n";
    else if(n == 3) cout << 2 << "\n";
    else if(n == 4) cout << 3 << "\n";
    else if(n == 5) cout << 3 << "\n";
    else cout << 4 << "\n";
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     cout << (i % 4) + 1 << " ";
    // }
    // cout << "\n";

    if(n <= 5)
    {
        if(n == 1)
        {
            cout << "1\n";
            return ;
        }
        else if(n == 2)
        {
            cout << "1 2\n";
        }
        else if(n == 3)
        {
            cout << "1 2 2\n";// 如果是三个的话那么
        }
        else if(n == 4)
        {
            cout << "1 2 2 3\n";// 四个的话
        }
        else if(n == 5)
        {
            cout << "1 2 2 3 3\n";
        }
    }
    else 
    {
        for(int i = 1 ; i <= n ; i ++)
        {
            cout << (i % 4) + 1 << " ";
        }
        cout << "\n";
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