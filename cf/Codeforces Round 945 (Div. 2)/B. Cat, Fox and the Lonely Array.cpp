#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int N = 100010;

int n;
int w[N];

// bool check(int x)
// {
//     // 枚举每一位
//     int tmp = 0; // 记录第一个区间的这位的值, 然后与后面的比较

//     for (int z = 0; z + x < n; z++)
//         if (w[z] & 1) // 直接判断第一位是不是
//         {
//             tmp = 1;
//             break; // 算出区间长度是x的情况, 第一位的是
//         }

//     int tmp1 = 0;
//     for (int i = 1; i <= 19; i++)
//     {
//         for (int j = 1; j + x < n; j++)
//         {
//             // 枚举每一个区间
//             for (int a = j; a < j + x; a++) // 从a开始到区间的右端点结束
//             {
//                 // 如果有一个1, 那么就直接是1
//                 if ((w[a] >> i) & 1 != tmp)
//                 {
//                     return false; // 这个x都不用看了
//                 }
//             }
//         }
//         // cout << tmp << " ";
//     }
//     return true; // 成功的每一个位置每一个区间都成功了, 那么就是合法的
// }

// void solve()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> w[i];
//     // 二进制问题拆成一位一位的算
//     // 有n个数字, 这个数字很大
//     // 然后问的时候一个长度k, 这个k可以使得每一个个长度为k的子串的直接|相等
//     // |运算就是有一个1就是1, 没有1就是0
//     // 要k个数|运算得到的数相等, 就要这k个数的每一位|运算都相等
//     // 所以我们遍历这些数的每一位, 然后找到k
//     // 可以试着二分查这个k最小是多少
//     int l = 0, r = N; // 最多是整个数组的长度
//     while (l < r)
//     {
//         cout << "l : " << l << " r : " << r << endl;
//         int mid = l + r >> 1;
//         if (check(mid))
//             r = mid; // 如果是真的说明是大于等于了, 我们要最小的
//         else
//             l = mid + 1; // 如果是假就是小了
//     }
//     cout << r << endl;
// }

void solve()
{
    // 判断最小的00串加1就可以得到k, 因为如果有1的话, 那么每一个取件都需要有一个1
    // 如果全是1的话, 那么最短的就是1
    // 但是有一个0的话, 这个0一定要跟着一个1, 所以找到最长的一个00段, 然后长度加一就是这个位置的k

    // 每次对所有数的同一个位置算出一个最小的k, 然后再每一位求一个最小的k.
    int n; cin >> n;
    for(int i = 0 ; i < n ; i ++ ) cin >> w[i];
    int k = 0;
    for(int i = 0 ; i < 20 ; i ++)
    {
        // 从最低位开始
        int tmp = 0;
        for(int j = 0 ; j < n ; j ++)
        {
            // 枚举所有的数字, 判断这位是1还是0, 如果这位是0的话, 那么就continue;
            // 如果是1的话那么就试着更新一下k
            if(((w[j] >> i) & 1) == 0 ) tmp ++;
            else
            {
                // cout << "tmp : " << tmp + 1<< endl;
                k = max(k, tmp + 1);
                // 这一位是1的话, 那么就重置一下tmp
                tmp = 0;
            }
            // 如果全是0的话, 那么直接就是不管了, 这意味没有限制呀
        }
        // 如果是全0, 那么长度就是1
        if(tmp == n) k = max(k, 1);
        else k = max(k, tmp + 1);// 最后一个尾巴也判断一下
    }
    cout << k << endl;
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
