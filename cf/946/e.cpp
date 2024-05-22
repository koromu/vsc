#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <map>

using namespace std;
typedef unsigned long long  ll;
const int N = 55, M = 100010;

int a[N], b[N];// 读入的花费和幸福值, 也就是价值
ll dp[M];// 前i天中幸福度位j的最小花费

void solve()
{
    ll m, x;
    cin >> m >> x;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int maxv = 0;
    for(int i = 1 ; i <= m ; i ++) {
        cin >> a[i] >> b[i];
        maxv += b[i];// 幸福值
    }
    int ans = 0;
    for(ll i = 1 ; i <= m  ; i ++)
    {
        // 枚举天数
        for(int j = maxv ; j >= b[i] ; j --)
        {
            if(dp[j - b[i]] + a[i] <= (i - 1) * x)// 算出到今天的钱够不够买这个, 要不然就不用更新了
            {
                dp[j] = min(dp[j], dp[j - b[i]] + a[i]);
                ans = max(ans, j);
            }
        }
    }
        // for(int j = m * x ; j >= 0 ; j --)
        //     if((i - 1) * x >= a[i])
        //         dp[i][j] = max(dp[i - 1][j], dp[i-1][j - a[i]] + b[i]);
        // cout << ans << endl;
    // for(int j = maxv ; j >= 0 ; j --)
    // {
    //     if(dp[j] <= (m - 1) * x)
    //     {
    //         cout << j << endl;
    //         return ;
    //     }
    // }
    cout << ans << endl;
        
}



int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}