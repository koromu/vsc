#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;

void solve()
{
    cin >> n;
    string s; 
    cin >> s;
    s = ' ' + s;
    // 从左到右找一个R找一个L, 中间是奇数的话就是1, 偶数就是0, 左边一个L, 
    int l = 0, r = 0;
    int ans = 0, num = 0;

    int now = 0;// 如果是1那么就是L, 如果是2那么就是R, 如果左边没有的话就是0
    for(int i = 1 ; i <= n ; i ++)
    {
        if(s[i] != '.')
        {
            if(now == 1)
            {
                if(s[i] == 'R') {
                    ans += num;
                    now = 2;
                }
                // 全都不会倒
                else now = 1;
            }
            else if(now == 2)
            {
                // 前一个是R, 现在是什么呢
                if(s[i] == 'L')
                {
                    if(num % 2 == 1 ) ans ++;
                    // 否则都不需要变化
                    now = 1;
                }
                else now = 2;
            }   
            else 
            {
                // 左边没有的话, 那么什么都不需
                if(s[i] == 'R')
                {
                    ans += num;
                    now = 2;
                }
                else now = 1;
            }
            num = 0;
        }
        else num ++;
    }
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