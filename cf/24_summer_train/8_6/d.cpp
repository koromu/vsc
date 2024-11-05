#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int n, k; cin >> n >> k;
    int l = 1, r = k;
    

    if(k == 1) {
        cout << n << "\n";
        return;
    }
    if(n == k) {
        cout << "1\n";
        return;
    }
    if(n % 2 == 0)
    {
        if(k >= n) cout << "1\n";
        else cout << "2\n";   
        return;
    }
    else 
    {
        // 如果是奇数的话
        // 分解因子
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                cout << i << "\n";
                return;
            }
        }
        cout << n << "\n";
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