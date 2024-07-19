#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;


void solve()
{   
    // 相邻参与者的不同才会产生一个不公平值
    // 所以每一位每一位的看, 因为每一位只有1和0, 按数序的0 ~ n的串室是有规律的
    // 第0位产生不公平值的周期为1 = 2^0, 也就是每一个的后一个和前一个都会产生一个不公平值, 但是我们只算一个方向的, 防止多算漏算
    // 第1位产生不公平值得周期为2 = 2^1, 也就是每两个相同的后有一个不同的相邻元素组
    // 第2位产生不公平值得周期为4 = 2^2, 也就是每四个相同的后有一个不同的相邻元素组
    // 类推……
    // 第n位产生不公平值得周期为1 << (n - 1) = 2^n, 也就是每2^n个相同的后有一个不同的相邻元素组
    // 
    // 第0位会产生的不公平值就是    n
    // 第1位会产生的不公平值就是    n / 2
    // 第2位产生的不公平值就是      n / (2 ^ 2)
    // ... 这里的n指的是连续数的个数
    int n; cin >> n;
    int tmp = n;
    int tmp1 = n;
    int ans = 0, i = 0;
    while(n)
    {
        i++;
        n >>= 1;
    }
    // cout << "i : " <<  i << endl;
    for(int j = 0 ; j <= i ; j ++)
    {
        // 每次加上
        tmp1 /= 2;
        ans += ( tmp / (1ll << j));
        // cout << "tmp1 : " << tmp1 << " tmp : " << ( tmp / (1ll << j)) << endl;
    }
    cout << ans << endl;
    return;
}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
