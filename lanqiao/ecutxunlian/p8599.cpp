#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// // 打表的方式, 先算出123456789 能组成多少个数字

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};// 一个数组, 然后进行全排列

// int count(int x, int y)
// {
//     int ans = 0;
//     for(int i = x ; i <= y ; i ++)
//     {
//         ans += a[i];// 从最高位开始填入
//         // 直接把区间的数加起来
//         ans *=10;
//     }

//     // cout << "ans : " << ans << endl;
//     return ans;
// }

// int main()
// {   
//     int n;
//     cin >> n;
//     int ans = 0;
//     while(1)
//     {
//         // 一直循环直到循环了所有的数组
//         // 读入了一个n, 然后我们遍历先遍历位数遍历到什么时候呢, 直到左半边的数大于n了
        
//         // 每次需要三段数字, 一段单独的整数, 一段分子, 一段分母
//         // 三段需要两个边界, 第一段是从1 到 i, 第二段是从i + 1 到 j, 第三段是从就j + 1 到 9
//         for(int i = 1 ; i <= 7 ; i ++)
//         {
//             // 最多到1000010, 所以最少要七位数
//             for(int j = i + 1; j + 1 <= 9 ; j ++)
//             {
//                 int num1 = count(1, i);
//                 int num2 = count(i + 1, j);
//                 int num3 = count(j + 1, 9);
//                 if(num1 + num2 / num3 == n)
//                     ans ++;
//             }
//         }
//         next_permutation(a, a + 9);
//         bool flag = false;
//         for(int i = 1 ; i <= 9; i ++ )
//         {
//             if(a[i] != i)
//             {
//                 flag = true;
//                 break;
//             }
//         }
//         if(!flag) break;// 如果完全相同那么就退出循环了
//     }
//     cout << ans << endl;
//     return 0;
// }
bool st[11];// 记录使用了哪些数
int ans, x;
int qmi(int x, int y)
{
    int res = 1;
    while(y)
    {
        if(y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}


void dfs(int u, int n)
{
    // 这个时候真的有u位
    if(u == 9)
    {
        int c = 0;
        // 如果是第九位
        for(int i = 1; i <= 7 ; i ++)
        {// 枚举一下第一个数
            for(int j = i + 1 ; j <= 8 ; j ++)
            {   // 枚举一下第二个数, 那么第三个是就是剩下的数字
                // 也就是把这个数字的前i位取出来
                c = (n / qmi(10, 9 - i));
                int c1 = (n - c * qmi(10, 9 - i)) / qmi(10, 9 - j);// 这个算分子
                int c2 = n % qmi(10, 9 - j);
                if(c + c1 / c2 == x && (c1 / (double)c2) == c1 / c2)
                    {
                        ans ++;
                        // cout << " c : " << c << " c1 : " << c1 << " c2 : " << c2 << endl;
                    }
            }
        }
        return ;
    }
    // 当前是第i位
    for(int i = 1 ; i <= 9 ; i ++)
    {
        if(!st[i])
        {
            // 如果是个false的话, 那么就就可以遍历
            st[i] = true;
            dfs(u + 1, n * 10 + i);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> x;

    // 使用dfs的形式来试试
    for(int i = 1 ; i <= 9 ; i ++ )
        st[i] = true, dfs(1, i), st[i] = false;// 从第1位开始的值开始

    cout << ans << endl;
    return 0;
}