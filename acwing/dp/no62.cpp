#include <iostream>
#include <vector>

using namespace std;
;

// 数位dp, 状态数组, f[i][j]
// 总共有i位, 当前位是j的合法的方案数

const int N = 11;
int l, r;
int f[N][10];
void init()
{
    // 处理边界
    for (int i = 0; i <= 9; i++) // 只有一位的情况
        if (i != 4)
            f[1][i] = 1;

    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
        {
            if (j == 4)
                continue;

            for (int k = 0; k <= 9; k++)
            {
                if (k == 4 || (j == 6 && k == 2))
                    continue;
                f[i][j] += f[i - 1][k];
            }
        }
}

int dp(int x)
{
    if (!x)
        return 1;
    vector<int> nums;
    while (x)
        nums.push_back(x % 10), x /= 10;
    int ans = 0 , last = 0;
    for(int i = nums.size() - 1 ; i >= 0 ; i --)
    {
        int num = nums[i];

        for(int j = 0 ; j < num ; j ++)
        {
            //当前位是j
            if(last == 4 || (last == 6 && j == 2)) continue;
            ans += f[i + 1][j];//加上有i位, 当前位是j的方案数
        }
        if(num == 4 ||(last == 6 && num == 2)) break;
        last = num;
        if(!i) ans ++;
    }

    return ans ;
}

int main()
{
    init();
    while (cin >> l >> r, l || r)
    {
        // 输入两个数, 如果两个数都为0就退出了
        cout << dp(r) - dp(l - 1) << endl;
    }

    return 0;
}