#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int N = 100010;

int n;
int w[N];

bool check(int x)
{
    // 枚举每一位
    int tmp = 0; // 记录第一个区间的这位的值, 然后与后面的比较

    for (int z = 0; z + x < n; z++)
        if (w[z] & 1) // 直接判断第一位是不是
        {
            tmp = 1;
            break; // 算出区间长度是x的情况, 第一位的是
        }
    int tmp1 = 0;
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j + x < n; j++)
        {
            // 枚举每一个区间
            for (int a = j; a < j + x; a++) // 从a开始到区间的右端点结束
            {
                // 如果有一个1, 那么就直接是1
                if ((w[a] >> i) & 1 != tmp)
                {
                    return false; // 这个x都不用看了
                }
            }
        }
        // cout << tmp << " ";
    }
    return true; // 成功的每一个位置每一个区间都成功了, 那么就是合法的
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    // 二进制问题拆成一位一位的算
    // 有n个数字, 这个数字很大
    // 然后问的时候一个长度k, 这个k可以使得每一个个长度为k的子串的直接|相等
    // |运算就是有一个1就是1, 没有1就是0
    // 要k个数|运算得到的数相等, 就要这k个数的每一位|运算都相等
    // 所以我们遍历这些数的每一位, 然后找到k
    // 可以试着二分查这个k最小是多少
    int l = 0, r = N; // 最多是整个数组的长度
    while (l < r)
    {
        cout << "l : " << l << " r : " << r << endl;
        int mid = l + r >> 1;
        if (check(mid))
            r = mid; // 如果是真的说明是大于等于了, 我们要最小的
        else
            l = mid + 1; // 如果是假就是小了
    }
    cout << r << endl;
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
