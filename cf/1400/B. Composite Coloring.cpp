#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 1010;
int a[N], color[N];
int w[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}; // 在后背的平方就大于1000
int res[N];
void solve()
{
    // 因为是一堆合数组成的数组
    // 如果两个合数的最大公约数不是1, 那么他们一定有一个相同的最小公因数
    // 可以根据最小公因数分类涂色
    // 所以枚举所有的数, 然后枚举所有质数, 看看那个可以把这个数整除
    // 对于质数, 一个数的最大质因子小于等于自己的二次方根
    // 所以先得到根号1000以内的正质数
    //这个手算一下就是了, 非常巧的就是11个, 所以可以分成11个颜色

    int n; cin >> n;
    memset(res, 0, sizeof(res));
    memset(color, 0, sizeof(color));

    for(int i = 1; i <= n ; i ++)
        cin >> a[i];
    int idx = 0;
    for(int i = 0 ; i < 11 ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
        {
            if(a[j] % w[i] == 0 && !res[j])
            {
                if(color[i] == 0) color[i] = ++idx;// 只加一次, 给用到的颜色发编号
                res[j] = color[i];
            }
        }
    }
    cout << idx << endl;
    for(int i = 1 ; i <= n ; i ++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

}

signed main()
{
    int _ ; cin >> _;
    while(_--) solve();
    return 0;
}
