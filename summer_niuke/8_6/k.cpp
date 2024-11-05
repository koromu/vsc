#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int p1, p2;
int f[N], last[27];// 记录最后一个字符出现的位置

void solve()
{
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    a = ' ' + a, b = ' ' + b;

    // 先找到一个字符串中从前开始的的一个b串，再从后往前找到最开始的一个b串
    for(int i = 1, j = 1 ; i <= n ; i ++ )
    {
        if(a[i] == b[j])
        {
            j++;
            if(j == m + 1)
            {
                p1 = i + 1;// 说明这个i是最后一个b串的最后一个字符
                break;
            }
        }
    }
    for(int i = n, j = 1 ; i >= 1 ; i -- )
    {
        if(a[i] == b[j])
        {
            j++;
            if(j == m + 1)
            {
                p2 = i - 1;// 说明这个i是最后一个b串的最后一个字符
                break;
            }
        }
    }
    cout << p1 << " " << p2 << "\n";

    for(int i = p1 - 1 ; i <= p2 + 1; i ++) 
        f[i] = 0;
    for(int i = 0 ; i <= 26 ; i ++) last[i] = 0;

    // 得到的区间就是p1 ~ p2
    // f[i]表示第i位置选或不选，然后本质不同字串多少个
    for(int i = p1 ; i <= p2 ; i ++)
    {
        f[i] = f[i - 1];// 不选这个位置的话字串增加 
        // cout << last[a[i] - 'a'] << "\n";
        f[i] = 2 * f[i - 1] - f[last[a[i] - 'a']];// 选择的话字串
        last[a[i] - 'a'] = i;
        cout << f[i] << "\n";
    }
    cout << f[p2] << "\n";
    // int p1, p2;
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     if(a[i] == b[1])
    //     {
    //         for(int j = 1 ; j <= m ; j ++)
    //         {
    //             if(a[i + j] != b[j])
    //             {
    //                // 如果没找到
    //                p1 = -1;
    //             }
    //         }
    //         p1 = i + m;// 找到
    //     }
    // }

    // for(int i = n ; i >= 1 ; i --)
    // {
    //     if(a[i] == b[1])
    //     {
    //         for(int j = 1 ; j <= m ; j ++)
    //         {
    //             if(a[i - j] != b[j])
    //             {
    //                 p2 = -1;
    //             }
    //         }
    //         p2 = i - m;
    //     }
    // }
    // int ans = 0;
    // if(p1 == -1 && p2 == -1) cout << 0 << endl;
    // else 
    // {
    //     if(p1 < p2)
    //     {
    //         // 如果相等的那么就是1
    //         // 如果4 6
            
    //     }
    //     else ans ++; 
    // }
    



}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

return 0;
}