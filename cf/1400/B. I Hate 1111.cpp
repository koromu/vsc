#include <iostream>
#include <algorithm>
#include <queue>

#define int long long
using namespace std;

const int N = 100010;

int w[] = {111111111, 1111111, 111111, 11111, 1111, 111, 11};

void solve()
{
    int n ; cin >> n;
    // 对于111111111, 1111111, 111111, 11111, 1111, 111, 11可以发现
    // 1111以后的关于1的一串数都可以被11 和 111 表示
    // 也就是被1111以后的关于1的一串数整除的数，可以表示为x = 11a + 111b
    // 所以这题意思就是看一个数能否被表示成11a + 111b
    // 也即是n = 11a + 111b成立 (其中a >= 0, b >= 0 是整数)
    // 然后很巧妙的令b = 11c + d (d < 11)
    // 化简把条件的式子变成了
    // n = 11a + 111(11c + d)
    // n - 111d = 11(a + 111c)
    // 因为a + 111c是整数
    // 所以要求就是n - 111d % 11 == 0, 也就是n - 111d能不能被11整除
    // 然后可以枚举d进行判断，根据证明d的范围就是0 ~ 11， 所以最多枚举11次
    for(int d = 0 ; n - 111 * d >= 0 ; d ++)
    {
        if((n - 111 * d) % 11 == 0)
        {
            puts("YES");
            return ;
        }
    }
    puts("NO");
}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}