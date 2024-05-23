#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 100010;

ll a[N], b[N];
ll mod[N] = {0};// 最大是k-1

int main()
{
    int n, k;
    cin >> n >> k;// k的倍数
    if(k == 0){
        cout << n * (n - 1) / 2  << endl;
        return 0;
    }
    // 答案就是一个到i的区间的的和, 如果和到j的区间的和同余k的话, 那么这两个区间的差值就是k的倍数
    // 所以算出一个每个余数出现的区间的个数, 然后算出所有的组合, 每个区间只会出现一次, 所以不会出现重复的组合
    for(int i = 1; i <= n; i ++) cin >> a[i];
    // mod[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        b[i] = b[i- 1] + a[i];
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        mod[b[i] % k] ++;// b中的前缀和会爆int, 然后变成负数, 然后就会越界re
    }

    // 处理好了后
    ll ans = 0;
    for(int i = 0 ; i < k ; i ++)
    {
        // 枚举所有的余数
        ans += ((mod[i] * (mod[i] - 1)) / 2);
    }
    cout << ans + mod[0]<< endl;
    
}

