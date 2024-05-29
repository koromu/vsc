#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <math.h>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 10000010, mod = 1e9 +7;

int f[N];// 问的是填满长度为N宽度为2的方案数, 这个状态表示我也不知道怎么来的, 网上的都不是很理解, 但是知道状态转移怎么来的了
// 因为定义这个f[i]表示, 填满前i个宽度为2的方案数
// 因为使用L和I形状的积木, 所以考虑最后填满的情况
// 可能是(1)一个I形的, 可能(2)是两个I形横过来的
// 也可能是一个L形的, 但是没填满, 所以为了填满, 可以(3)最少再用一个L形的, 次少用一个I加一个L
// 次次少两个I两个L, 这样长度再加1, 一直到长度直接填满, 所以这个状态是一个累加的状态

// 根据定义
// (1) f[i] += f[i - 1], (2) f[i] += f[i - 2] (3) f[i] += (f[i - 3] + f[i - 4] + f[i - 5] + ... ), 直到填满, 也就是从0转移过来
// 也就是当前状态可能是由前面四种状态转移而来
// 因为这个L形是可以翻转的

signed main()	
{
    int n; cin >> n;
    f[0] = 1;// 这样的递推式, 还需要f[3] 要用到f[2], f[4] 用到 f[1]
    f[1] = 1;
    f[2] = 2;

    for(int i = 1 ; i <= n ; i ++)
    {
        // 枚举每一列, 然后在合法状态加上前面三种转移方程
        // for(int j = 3 ; i - j >= 0 ; j ++)
        // {
        //     f[i] = 2 * f[i - j] % mod;
        // }
        if(i >= 3) f[i] = (2 * f[i - 1] + f[i - 3] ) % mod;
    }
    // n * (n / 2) 过不了了, 所以要化简一下, 一般就是把累加式子转换一下
    cout << f[n] << endl;
    return 0;
}