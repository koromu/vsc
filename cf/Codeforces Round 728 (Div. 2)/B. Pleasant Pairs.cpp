#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <map>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;

int w[N];

// 因为是不同的数, 所以可以存到map

void solve()
{   
    int n, ans = 0; cin >> n;
    // unordered_map<int, int> ha;
    map<int, int> a;
    int tmp;
    bool st[N];
    memset(st, 0, sizeof st);
    for(int i = 1 ; i <= n ; i ++)// 下标从1开始, 也就是从a[1]开始 
    {
        cin >> w[i];
        a[w[i]] = i;// tmp下标是i
    }
    // 下标之和最多到n + n - 1, 最少是1 + 2, 枚举下标之和, 然后
    // 枚举一个
    for(int i = 1 ; i <= n ; i ++)
    {
        // 枚举a, 然后枚举a的倍数
        for(int j = 1 ; j * w[i] <= 2 * n - 1; j ++)
        {
            if(a[j] && w[i] != j && a[j] + i == w[i] * j) // j是这个倍数, w[i]也是这个倍数, 并且w[i]一定存在的
            {
                // 如果j这个数存在, 那么判断索引
                ans ++;
            }
        }
    }
    cout << ans / 2 << endl;
}
signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
