#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 11; // 考虑到最大的数, 2^32=4294967296是一个十进制的10位数
// 需要一个数组, 每一位可以分成两种情况, 左边是选择0 ~ x(n) - 1的情况,右边是考虑x的情况
// 如果是左边的话, 那么后面的位数可以随便填, 后面的方案就可以用预处理的数组来求

// 如果是右边的话, 那么再考虑上面一样的情况, 分为选择0 ~ x(n-1) - 1的情况, 右边是考虑x(n-1)的情况
// 如果是左边的话, 那么后面的位数可以随便填, 后面的方案就可以用预处理的数组来求

// 依次类推, 需要的就是预处理的数组
// 预处理的数组就是要能直接求出左边的方案.
// 使用一种递推的方法, 当前位是0 ~ x(n) - 1后面的位数是不减序列的方案数
LL f[N][N]; // f[i][j]表示总共i位数, 当前位是j的不减序列的方案数

void init()
{
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = j; k <= 9; k++)
            {
                // f[0][0] 用到了f[-1][0], 所以i从1开始, f[1][0] 用f[0][0] f[1][1] 用f[0][1] ... f[0][9]0位数不存在, 所以从2开始
                // 更新f[2][0] f[2][1] f[2][2] f[2][3] f[2][4] f[2][5] f[2][6] f[2][7] f[2][8] f[2][9]
                // 用了f[1][0] f[1][1] f[1][2] f[1][3] f[1][4] f[1][5] f[1][6] f[1][7] f[1][8] f[1][9], 一位数, 全部都是1, 所以初始化一下, 这些数组就行了
                f[i][j] += f[i - 1][k];
            }
        }
    }
}
LL dp(int n)
{
    if (!n)
        return 1;
    // 以x为最大的数字, 也就是边界, 从最高位开始, 考虑每一位
    vector<int> nums;

    while (n)
        nums.push_back(n % 10), n /= 10;

    LL ans = 0, last = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i]; // 不需要判断是否大于0, 如果是0, 一个都进不去, 直接跳过
        // 否则就进入下一层, 上一层的数是last, 那么下一层得从last开始, 一直到x - 1
        if (x < last)
            break; // 取出当前位后, 如果当前位小于上一个, 说明不符合要求, 直接退出

        // 如果last == x, 那么直接跳过, 等到最后来处理这种情况
        for (int j = last; j < x; j++) // 然后选择last ~ x - 1的数字
        {
            ans += f[i + 1][j]; // 当前位是j, 总共有i + 1位, 因为i 从0到 nums.size() - 1, 所以i + 1 从1到nums.size()位
        }
        last = x;
        if (!i)
            ans++; // 这里就是在最后算上所有j == x的情况
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