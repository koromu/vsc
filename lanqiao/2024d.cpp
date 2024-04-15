#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int N = 100010;
int f[N];

string w[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    // 最少要删除多少个数, 使得变成一个接龙序列
    // 也就是看一个序列的最长接龙序列是多长, 然后用总长减去最长序列长, 就可以得到最少删除的个数了
    // 问题变成求一个序列的最长接龙序列(可以不连续), 可以用动态规划求解
    // 数组f[i]表示, 从前i个中选出的最长接龙序列的长度
    int ans = 0;
    for (int j = 1; j <= n; j++)
    {
        memset(f, 0, sizeof f);
        f[j] = 1; // 当前是1的话, 直接就是可以选, 当然答案肯定也需要包含不选第一个的情况
        for (int i = j + 1; i <= n; i++)
        {                           // 不选这个位置时, 答案就是相当于长度是i-1的方案数
            if (w[i][0] == w[i - 1][w[i - 1].size() - 1]) // 判断是否是合法的
            {
                f[i] = f[i - 1] + 1;
                ans = max(f[i], ans);
            }
        }
    }
    cout << n - ans << endl;
    return 0;
}