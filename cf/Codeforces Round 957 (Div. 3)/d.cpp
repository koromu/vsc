#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int n, m, k;
string a; 

// void solve()
// {   
//     cin >> n >> m >> k;
//     cin >> a;
//     // 首先在岸上, 直接跳跃到最远的木头上
//     // 遍历一遍字符串
//     // 如果现在是L C W
//     // 如果是W, 就往前遍历k个格子, 是否有陆地
//     for(int i = 0 ; i < a.size() ;)
//     {
//         if(i == 0 || a[i] == 'L')
//         {
//             if(i + m >= a.size())
//             {
//                 puts("YES");
//                 return;
//             }
//             bool f1 = false;
//             for(int j = m - 1 ; j >= 0 ; j --)
//             {
//                 if(a[i + j] == 'L')
//                 {
//                     i += j;// 跳到这里来
//                     f1 = true;
//                     break;
//                 }
//             }
//             if(!f1)
//             {
//                 // 如果没找到
//                 for(int j = m - 1 ; j >= 0 ; j --)
//                 {
//                     if(a[i + j] == 'W')
//                     {
//                         i += j;// 跳到这里来
//                         f1 = true;
//                         break;
//                     }
//                 }
//             }
//             if(!f1) 
//             {
//                 puts("NO");
//                 return;
//             }
//         }
//         int posc = -1, posl = -1;
//         if(a[i] == 'W')
//         {
//             if(i + k >= a.size())
//             {
//                 puts("YES");
//                 return;
//             }
//             for(int j = 0 ; j < k ; j ++)
//             {
//                 if(a[i + j] == 'C')
//                 {
//                     posc = i + j;
//                     break;
//                 }
//             }
//             // 或者出来了
//             for(int j = 0 ; j < k ; j ++)
//             {
//                 if(a[i + j] == 'L')
//                 {
//                     posl = i + j;
//                     break;
//                 }
//             }
//             if(posc < posl || posl == -1)
//             {
//                 puts("NO");
//                 return;
//             }
//             else
//             {
//                 i += posl;
//             }
//         }
//     }
//     puts("YES");
//     return;
// }

int dp[N];

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    string a ; cin >> a;
    // 如果当前这一格是水的话，那么枚举前面的格子
    // 从i - m开始，有可能m比i大，所以从其中更小的值枚举
    // 如果第i - j格子是L那么到i这个格子就要看i是什么
    // i是水的话，游泳步数就要加1，如果是l那么游泳数就是0

    // 如果i - j是w，那么只能看后一个，看的规则也是一样的
    // 然后用游泳的最小距离和k比，如果小于k那么就是合法的，如果最小的大于就是不合法

    a = 'L' + a + 'L';// 这样可以直接递推，只需要要看到n + 1的最小游泳距离就行了
    for(int i = 1 ; i <= n + 1 ; i ++) dp[i] = 1e9 + 7;
    // for(int i = 1 ; i <= n + 1 ; i ++) cout << dp[i] << " ";
    // std::cout << a << endl;
    for(int i = 1 ; i <= n + 1 ; i ++)
    {
        if(a[i] == 'L' || a[i] == 'W')
            for(int j = max(i - m, 0ll) ; j < i ; j ++)// 枚举的是跳跃的步数
            {
                // std::cout  << "i : " << i << " a[i] : " << a[i] << " j : " << j  << " a[j] : " << a[j]  << endl;
                if(a[j] == 'L')// 如果从l开始跳
                {
                    // std::cout << "dp[i] : " << dp[i] << " dp[j] : " << dp[j] << endl;
                    dp[i] = min(dp[i], dp[j]);    
                }
                else if(a[j] == 'W' && j == i - 1 )
                {
                    // std::cout << "dp[i] : " << dp[i] << " dp[j] : " << dp[j] << endl;
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
    }
    // for(int i = 1 ; i <= n + 1; i ++) std::cout << dp[i] << " ";
    if(dp[n + 1] <= k) puts("YES");
    else puts("NO");   
}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
