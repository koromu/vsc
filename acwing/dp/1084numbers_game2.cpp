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
