#include <iostream>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 110;

int mp[N * N + 10];

int gcd(int a, int b)
{ 
    return b ? gcd(b, a % b) : a;// 因为b是a mod b的余数, 二如果a 被 b整除, 那么b 也会整除 b且余1, 二此时的a就是上一层整除上一层a的b
}

signed main()
{
    int n, m, d; cin >> n >> m >> d;
    for(int i = 1 ; i <= n * m ; i ++)
    {
        cin >> mp[i];
        // t1 = gcd(t1, mp[i]);
    }
    // cout << t1 << endl;
    sort(mp + 1, mp + n * m + 1);// 排序
    // 看每一个数是不是都相差d的x次倍, 这个x有可能是0
    // 所以每一个数都可以表示成
    // x1 * d + c1
    // x2 * d + c1
    // 也就是相差(x1 - x2)倍的d, 整数倍, 余数相同
    // 所以同余
    int r = mp[1] % d;
    for(int i = 2 ; i <= n * m ; i ++)
    {
        if(r != mp[i] % d)
        {
            puts("-1");
            return 0;
        }
    }

    // 然后找到中位数
    // 偶数中位数有两个
    int minv1 = mp[(1 + n * m) / 2], minv2 = mp[(1 + n * m) / 2 + 1];
    // cout << "m1 : " << minv1 << " m2 : " << minv2 << endl;
    // 找到了这个中间值
    int ans1 = 0, ans2 = 0;
    for(int i = 1 ; i <= n * m; i ++)
        ans1 += abs(mp[i] - minv1) / d;
        // 计算一遍最小步数
    for(int i = 1 ; i <= n * m ; i ++)
        ans2 += abs(mp[i] - minv2) / d;
        // 计算一遍最小步数
        // cout << "ans1 : " << ans1 << " ans2 : " << ans2 << endl; 
    cout << min(ans1, ans2) << endl;

    // 所有数的gcd得是d的倍数, 否则无解

    // 所以是nlogn?
    return 0;
}
