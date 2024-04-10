#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 11; // 考虑到最大的数,2e9是一个十进制的10位数

LL f[N][N]; // f[i][j]表示总共i位数, 当前位是j的相邻差值大于等于2的方案数

void init()
{
    // 有1位, 当前位是i的方案数是1
    for (int i = 0; i <= 9; i++)//调试发现, f[2][2]出现异常, 发现当位数是2, 当前位是2, 那么可以有0 4 5 6 7 8 9 = 7种, 再看初始化的情况, 少了0这种情况, 所以改变初始化f[1][0]也要等于1
        f[1][i] = 1;
    for (int i = 2; i <= N; i++) // 直接从2开始
    {
        for (int j = 0; j <= 9; j++) // 只要 j - k 的绝对值大于等于2就更新
        {
            for (int k = 0; k <= 9; k++)
            {
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
            }
        }
    }
}
LL dp(int n)
{
    if (!n)
        return 0;
    vector<int> nums;

    while (n)
        nums.push_back(n % 10), n /= 10;

    LL ans = 0, last = -2;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];

        for (int j = (i == nums.size() - 1); j < x; j++) // 此时j可以任意知道和
        {
            if (abs(j - last) >= 2)
                ans += f[i + 1][j];
        } // 还是不可以等于x, 如果上一位取的是x, 只会对下一位也等于x(下一位的上限)的情况造成影响, 不会对下一位取 0 ~ a(n) - 1的情况造成影响

        if (abs(x - last) < 2)
            break;
        // 如果右边的情况走不了, 那么就走左边, 然后break;
        last = x;
        if (!i)
            ans++;
    } // 这里处理的时候有n位时的情况, 每次记录了上一位是什么数字, 然后更新下一位的数字

    for (int i = nums.size() - 1; i >= 1; i--) // 遍历1个前导零,2个前导零,3个前导零一直到n-1个前导零的情况
    {                                          // 所以这里的数字所有的都是合法的,
        // 总共有i位, 当前位是j, 所以只要f[i][j]是正确的, 就不会漏掉某种情况
        for (int j = 1; j <= 9; j++)
            ans += f[i][j]; // 但是这里不能是0, 如果是0的话就是等i减少的情况, i的变化就代表了有多少次取到0的情况
    }

    return ans;
}
int main()
{
    LL l, r;
    init();
    while (cin >> l >> r)
    {
        cout << dp(r) - dp(l - 1) << endl;
    }
    return 0;
}