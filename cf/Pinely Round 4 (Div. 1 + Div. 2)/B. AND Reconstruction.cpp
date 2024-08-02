#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

string get01(i64 x)
{
    string res = "";
    while(x)
    {
        res += (x & 1ll) ? '1' : '0';
        x >>= 1;
    }
    // reverse(res.begin(), res.end());
    return res;
}

// int getval(string s)
// {
//     int res = 0;
//     int a = 1;
//     for(int i = 0 ; i < s.size() ; i ++)
//     {
//         res = res + a * (s[i] - '0');
//         a *= 2;
//     }
//     return res;
// }

// int l[N];
i64 w[N], ans[N];

void solve()
{
    // int n, maxv = 0;

    // // std::cout << getval("1011") << "\n";
    // // std::cout << get01(15) << "\n";
     
    // cin >> n;
    // int w[N], ans[N];
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     cin >> w[i];
    //     while(w[i])
    //     {
    //         w[i] -= (w[i] & (-w[i]));
    //         l[i]++;
    //     }
    // }

    // for(int i = 2 ; i <= n ; i ++)
    // {
    //     if(l[i] < l[i - 1])
    //     {
    //         cout << -1 << "\n";
    //         return;
    //     }
    // }

    // // 至少要他们需要的1的个数在减少
    // if(n == 1)
    // {
    //     std::cout << w[1] << " " << ((1 << 31) - 1) << "\n"; 
    //     return ;
    // }
    // else if(n == 2)
    // {
    //     std::cout << w[1] << " " << ((1 << 31) - 1) << " " << w[3] << "\n";
    //     return;
    // }
    // ans[1] = w[1];
    // ans[2] = 1 << 31 - 1;
    // ans[3] = w[3];
    // for(int i = 3 ; i <= n ; i ++)// 从第三个元原数组开始
    // {
    //     // 第一个直接取第一个数, 第二个数直接拉满
    //     // 第三个数也等于第三个数
    //     // 从第四个数开始, 依次判断第4个数的每一位和第三个数的每一位
    //     // 得到他们的二进制位
    //     string s = get01(w[i]);
    //     string t = get01(ans[i - 1]);
    //     // std::cout << s << " " << t << "\n";
    //     string tmp = "";
    //     for(int j = 0 ; j < s.size() ; j ++)
    //     {
    //         if(s[j] == '1' && t[j] == '1')
    //         {
    //         //    ans[i] += (1 << (j));
    //             tmp += '1';
    //         }
    //         else if(s[j] == '1' && t[j] == '0')
    //         {
    //             std::cout << "-1" << "\n";
    //             return;
    //         }
    //         else if(s[j] == '0' && t[j] == '1')
    //         {
    //             tmp += '0';
    //         }
    //         else if(s[j] == '0' && t[j] == '0')
    //         {
    //             tmp += '1';
    //             // ans[i] += (1 << (j));
    //         }
    //     }
    //     ans[i + 1] = getval(tmp);
    //     // std::cout << ans[i] << " ";
    // }
    // for(int i = 1 ; i <= n ; i ++) std::cout << ans[i] << " ";
    // std::cout << "\n";

    int n;
    cin >> n;
    for(int i = 0 ; i <= n + 5 ; i ++){
        w[i] = ans[i] = 0;
    }
    for(int i = 1 ; i <= n - 1 ; i ++) cin >> w[i];

    // 对于一个数都进行合法的获得, 然后最后再判断这整个数组能否得到完整的原数组
    // for(int i = 1 ; i <= n - 1 ; i ++)
    // {
    //     // 对w[i]每一位进行判断
    //     string wi = get01(w[i]);
    //     // cout << wi << "\n";
    //     for(int j = 0 ; j < wi.size() ; j ++)
    //     {
    //         if(wi[j] == '1')
    //         {
    //             ans[i] |= (1ll << j);
    //             ans[i + 1] |= (1ll << j);
    //         }// 因为为了获得w[i], 这个位置上必须有1
    //     }
    // }
    for (int i = 1; i <= n; i++) {
        ans[i] = w[i - 1] | w[i];
    }

    // for(int i = 1 ; i <= n ; i ++) cout << ans[i] << " ";
    // cout << "\n";

    for(int i = 1 ; i <= n - 1 ; i ++)
    {
        // cout << (ans[i] & ans[i + 1] ) << " " << w[i] << "\n";
        if((ans[i] & ans[i + 1]) != w[i])
        {
            cout << -1 << "\n";
            return;
        }
    }

    for(int i = 1 ; i <= n ; i ++) cout << ans[i] << " ";
    cout << "\n";
}    


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();

return 0;
}