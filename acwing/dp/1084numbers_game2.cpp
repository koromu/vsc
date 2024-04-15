// #include <iostream>
// #include <vector>

// using namespace std;

// typedef long long ll;

// const int N = 35;
// int a, b, n;
// int f[N][N]; // 当前有i位, 当前位是j的方案数

// int qmi(int a, int k)
// {
//     if (k == 0)
//         return 1;
//     int res = 0;
//     while (k)
//     {
//         if (k & 1)
//             res = res * a;
//         a *= a;
//         k >>= 1;
//     }
//     return res;
// }

// void init()
// {
//     for (int i = 1; i <= N; i++)
//     {
//         // 当前位是i
//         f[i][1] = qmi(2, i - 1);
//     }
// }

// int dp(int x)
// {
//     vector<int> nums;
//     while (x)
//     {
//         nums.push_back(x % 10);
//         x /= 10;
//     }

//     int res = 0;
//     for (int i = nums.size() - 1; i >= 1; i--)
//     {
//         int num = nums[i]; // 拿出最高位
//         // 不管这个位置是不是1, 都要加上不包含这一位的方案数
//         if (num)
//         {
//             res += f[i - 1][1]; // 当前位是1的方案数, 先考虑后面安全的方案数, 后面i-1位都有两种可能性, 1 或者 0, 也就是2^i
//             if (num > 1)
//             {
//                 res += f[i][1];
//                 break;
//             }
//         }
//         if (i == 1)
//         {
//             if (nums[0] >= 1)
//                 res += 2;
//             else
//                 res++;
//         }
//     }
//     return res;
// }

// int main()
// {
//     init();
//     cin >> a >> b >> n;
//     while (cin >> a >> b >> n)
//     {
//         cout << dp(b) - dp(a - 1) << endl;
//     }
//     return 0;

#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

typedef long long ll;

const int N = 12;
int a, b, n;

int f[N][12][110]; // 当前有i位, 当前位是j, 各个位置的数相加modN得0的情况

int mod(int x)
{
    return (x % n + n) % n;
}

void init()
{
    //处理边界
    memset(f, 0, sizeof f);
    //总共有1位, 当前位时0 ~ 9 mod n余数是余数
    for(int i = 0 ; i <= 9 ; i ++) f[1][i][i % n]++;
    
    for(int i = 2 ; i <= N ; i ++)
        for(int j = 0 ; j <= 9 ; j ++)
            for(int k = 0 ; k < n ; k ++)
                for(int x = 0 ; x <= 9 ; x ++)
                {
                    f[i][j][k] = f[i-1][x][mod(k - j)];
                }
}

int dp(int x)
{
    vector<int> nums;
    while (x)
    {
        nums.push_back(x % 10);
        x /= 10;
    }

    int res = 0, last = 0;
    for (int i = nums.size() - 1; i >= 0; i--)//一直到当前是1位, 也就是下标是0
    {
        int num = nums[i]; // 拿出最高位
        // 不管这个位置是不是1, 都要加上不包含这一位的方案数
        for(int j = 0 ; j < num ; j ++ )//加上左分支, 也就是任意选择的可能性
        {
            res += f[i + 1][j][mod(- last)];
            //对于i位数字, 这个是可以直接用的, 不需要知道后面的数字, 因为再预处理是从低位开始处理的
            //现在使用时, 就直接使用f[i][j][k]
        }
        last += num;
        if(!i && last % n == 0) res ++; 
    }
    return res;
}

int main()
{
    while(cin >> a >> b >> n)
    {   
        init();
        cout << dp(b) - dp(a - 1) << endl;
    }
    return 0;
}