#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 2e5;
int w[N];
int f[N];
// 所以我们要存一个区间起点和终点, 然后还有长度
unordered_map<int, int> ha;

void solve()
{
    int n, d; cin >> n >> d;
    int ans = 1e18 +10; // 取最小余数
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];        
    }
    sort(w + 1, w + n + 1);
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     if(ans > d % w[i])
    //     {
    //         ans = d % w[i];
    //         cout << w[i] << endl;
    //     }
    // }
    
    cout << ans << endl;

    return ;
}


signed main()
{
    int _ = 1; // cin >> _;
    while(_--) solve();
    return 0;
}