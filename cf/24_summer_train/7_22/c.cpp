#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;

const int N = 200010;
int w[N];
vector<int> v1;
int a, b; 
bool check()
{
    return a < b;
}
// void solve()
// {
//     char ans[N];
//     cin >> a >> b;
//     string s; cin >> s;
//     s = ' '+ s;
//     for(int i = 1 ; i <= s.size() - 1 ; i ++) 
//         if(s[i] == '1') b--;
//         else if(s[i] == '0') a--;
//     // cout << a << " " << b << endl;
//     if(a < 0 || b < 0) 
//     {
//         puts("-1");
//         return;
//     }
//     for(int i = 1, j = s.size() - 1 ; i <= j; i ++, j --)
//     {
//         if(i == j && s[i] == '?')
//         {
//             // cout << a <<  " " << b << endl;
//             if((a == 1 && b == 0))
//             {
//                 ans[i] = '0';
//             }
//             else if((a == 0 && b == 1))
//             {
//                 ans[i] = '1';
//             }
//         }
//         else 
//         {
//             if(s[i] == '?' && s[j] == '?')
//             {
//                 if(check())
//                 {
//                     if(b >= 2)
//                     {
//                         b-=2;
//                         ans[i] = ans[j] = '1';
//                     }
//                     else 
//                     {
//                         puts("-1");
//                         return;
//                     }
//                 }
//                 else 
//                 {
//                     if(a >= 2)
//                     {
//                         a-=2;
//                         ans[i] = ans[j] = '0';
//                     }
//                     else 
//                     {
//                         puts("-1");
//                         return;
//                     }
//                 }
//             }
//             else if(s[i] == '?')
//             {
//                 if(s[j] == '1')
//                 {
//                     if(b)
//                     {
//                         b--;
//                         ans[i] = ans[j] = '1';
//                     }
//                     else 
//                     {
//                         puts("-1");
//                         return;
//                     }
//                 }
//                 else
//                 {
//                     if(a)
//                     {
//                         a--;
//                         ans[i] = ans[j] = '0';
//                     }
//                     else 
//                     {
//                         puts("-1");
//                         return;
//                     }
//                 }
//             }
//             else if(s[j] == '?')
//             {
//                 if(s[i] == '1')
//                 {
//                     if(b)
//                     {
//                         b--;
//                         ans[i] = ans[j] = '1';
//                     }
//                     else 
//                     {
//                         puts("-1");
//                         return;
//                     }
//                 }
//                 else
//                 {
//                     if(a)
//                     {
//                         a--;
//                         ans[i] = ans[j] = '0';
//                     }
//                     else 
//                     {
//                         puts("-1");
//                         return;
//                     }
//                 }
//             }
//             else
//             {
//                 if(s[i] != s[j])
//                 {
//                     puts("-1");
//                     return;
//                 }
//                 else if(i == j)
//                 {
//                     if(a != 0 || b != 0)
//                     {
//                         puts("-1");
//                         return;
//                     }
//                     else ans[i] = ans[j] = s[i];
//                     // break;
//                 }
//                 else 
//                     ans[i] = ans[j] = s[i];
//             }
//         }
//     }
//     for(int i = 1 ; i <= s.size() - 1 ; i ++) cout << ans[i];
//     cout << endl;
// }

void solve()
{
    int a, b; cin >> a >> b;
    string s; cin >> s;
    s = ' ' + s;
    char ans[N];
    for(int i = 1 ; i <= s.size() - 1 ; i ++) 
        if(s[i] == '1') b--;
        else if(s[i] == '0') a--;
    for(int i = 1, j = s.size() - 1 ; i <= j ; i ++, j --)
    {
        if(s[i] == '?' && s[j] != '?')
        {
            if(s[j] == '1')
            {
                if(b)
                {
                    ans[i] = ans[j] = '1';
                    b--;
                }
                else 
                {
                    puts("-1");
                    return;
                }
            }
            else
            {
                if(a)
                {
                    ans[i] = ans[j] = '0';
                    a--;
                }
                else 
                {
                    puts("-1");
                    return;
                }
            }
        }
        else if(s[i] != '?' && s[j] == '?')
        {
            if(s[i] == '1')
            {
                if(b)
                {
                    ans[i] = ans[j] = '1';
                    b--;
                }
                else 
                {
                    puts("-1");
                    return;
                }
            }
            else
            {
                if(a)
                {
                    ans[i] = ans[j] = '0';
                    a--;
                }
                else 
                {
                    puts("-1");
                    return;
                }
            }
        }
        else if(s[i] == '?'&& s[j] == '?')
        {
            continue;
        }
        else
        {
            if(s[i] != s[j])
            {
                puts("-1");
                return;
            }
            else ans[i] = ans[j] = s[i];
        }
    }
    // 处理完之后剩下, 要确定是一个回文字符串, 然后剩余两个问号的

    for(int i = 1 ; i <= s.size() - 1 ; i ++)
    {

    }
    for(int i = 1 ; i <= s.size() - 1 ; i ++) cout << ans[i];
    cout << endl;
}   

signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}
 
// -1
// 00
// 0000101001010000
// -1
// -1
// 01001110000001110010
// -1
// 1000110001
// -1
// -1
// 101101
// 000101101000
// -1
// -1
// -1
// 00000000000000
// 01100110
// 011100101001110
// 011010101101010110
// -1
// 1011000001101


// 101010000010101
// 00
// 0000101001010000
// -1
// -1
// 01001110000001110010
// -1
// 1000110001
// -1
// -1
// 101101
// 000101101000
// -1
// -1
// -1
// 00000000000000
// 01100110
// 011100101001110
// 011001101101100110