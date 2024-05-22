#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef unsigned long long ull;
const int N = 200010;

void solve()
{
    // int n;
    // cin >> n;
    // string a;
    // cin >> a;
    // int N = 0, S = 0, E = 0, W = 0;
    // for (int i = 0; i < a.size(); i++)
    // {
    //     if (a[i] == 'N')
    //         N++;
    //     else if (a[i] == 'S')
    //         S++;
    //     else if (a[i] == 'E')
    //         E++;
    //     else
    //         W++;
    // }

    // // 统计完了之后判断是否有一种情况成立, 还要注意的是是否合法
    // // 如果有N也有S的话, 那么判断是否相等
    // // 如果有W也有N的话, 那么判断是否相等
    // // 否则判断N/S/W/N是否是偶数
    // cout << "N : " << N << " S : " << S << " E : " << E << " W : " << W << endl;
    // if ((N && S && (N != S)) || (W && E && (W != E)))
    //     {
    //         puts("NO");
    //         return ;
    //     }

    // if (N && S && (N == S))
    // {// N和s都存在的情况
    //     if (W && E && (W == E))
    //     {//S E W N 都存在的情况
    //         //
    //         for (int i = 0; i < a.size(); i++)
    //             cout << 'R';
    //     }
    //     else
    //     {
    //         if (W && W % 2 == 0)
    //         {// N S W
    //             int c = W / 2;
    //             for(int i = 0 ; i < a.size() ; i ++)
    //             {
    //                 if(a[i] == 'N' || a[i] == 'S') {
    //                     cout << 'R';
    //                     continue;
    //                 }
    //                 if(c)
    //                 {
    //                     cout << 'R';
    //                     c--;
    //                 }
    //                 else cout << 'H';

    //             }
    //         }
    //         else if (E && E % 2 == 0)
    //         {// N S E
    //             int c = E / 2;
    //             for(int i = 0 ; i < a.size() ; i ++)
    //             {
    //                 if(a[i] == 'N' || a[i] == 'S') {
    //                     cout << 'R';
    //                     continue;
    //                 }
    //                 if(c)
    //                 {
    //                     cout << 'R';
    //                     c--;
    //                 }
    //                 else cout << 'H';

    //             }
    //         }
    //         else
    //         {// 错误的情况
    //             puts("NO");
    //         }
    //     }
    // }
    // else if (W && E && (W == E))
    // {// 都存在的情况在上面
    //     if (N && N % 2 == 0)
    //     {// W E N
    //         int c = N / 2;
    //         for(int i = 0 ; i < a.size() ; i ++)
    //         {
    //             if(a[i] == 'W' || a[i] == 'E') {
    //                 cout << 'R';
    //                 continue;
    //             }
    //             if(c)
    //             {
    //                 cout << 'R';
    //                 c--;
    //             }
    //             else cout << 'H';

    //         }
    //     }
    //     else if (S && S % 2 == 0)
    //     {// W E S
    //         int c = S / 2;
    //         for(int i = 0 ; i < a.size() ; i ++)
    //         {
    //             if(a[i] == 'W' || a[i] == 'E') {
    //                 cout << 'R';
    //                 continue;
    //             }
    //             if(c)
    //             {
    //                 cout << 'R';
    //                 c--;
    //             }
    //             else cout << 'H';

    //         }
    //     }// 只存在N或者S的情况, 还有一个是单数
    //     else
    //     {// 错误的
    //         puts("NO");
    //     }
    // }
    // else if(N || S)
    // {
    //     if(W || E)
    //     {
    //         if(N && N % 2 ==0)
    //         {
    //             if(W && W % 2 == 0)
    //             {
    //                 int c1 = N / 2, c2 = W / 2;
    //                 for(int i  = 0 ; i < a.size() ; i ++)
    //                 {
    //                     if(a[i] == 'N')
    //                     {
    //                         if(c1)
    //                         {
    //                             cout << 'R';
    //                             c1--;
    //                         }
    //                         else
    //                         {
    //                             cout << 'H';
    //                         }
    //                     }
    //                     else
    //                     {
    //                         if(c2)
    //                         {
    //                             cout << 'R';
    //                             c2--;
    //                         }
    //                         else cout << 'H';
    //                     }
    //                 }
    //             }
    //             else
    //             {
    //                 int c1 = N / 2, c2 = E / 2;
    //                 for(int i  = 0 ; i < a.size() ; i ++)
    //                 {
    //                     if(a[i] == 'N')
    //                     {
    //                         if(c1)
    //                         {
    //                             cout << 'R';
    //                             c1--;
    //                         }
    //                         else
    //                         {
    //                             cout << 'H';
    //                         }
    //                     }
    //                     else
    //                     {
    //                         if(c2)
    //                         {
    //                             cout << 'R';
    //                             c2--;
    //                         }
    //                         else cout << 'H';
    //                     }
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             if(W && W % 2 == 0)
    //             {
    //                 int c1 = S / 2, c2 = W / 2;
    //                 for(int i  = 0 ; i < a.size() ; i ++)
    //                 {
    //                     if(a[i] == 'S')
    //                     {
    //                         if(c1)
    //                         {
    //                             cout << 'R';
    //                             c1--;
    //                         }
    //                         else
    //                         {
    //                             cout << 'H';
    //                         }
    //                     }
    //                     else
    //                     {
    //                         if(c2)
    //                         {
    //                             cout << 'R';
    //                             c2--;
    //                         }
    //                         else cout << 'H';
    //                     }
    //                 }
    //             }
    //             else
    //             {
    //                 int c1 = S / 2, c2 = E / 2;
    //                 for(int i  = 0 ; i < a.size() ; i ++)
    //                 {
    //                     if(a[i] == 'S')
    //                     {
    //                         if(c1)
    //                         {
    //                             cout << 'R';
    //                             c1--;
    //                         }
    //                         else
    //                         {
    //                             cout << 'H';
    //                         }
    //                     }
    //                     else
    //                     {
    //                         if(c2)
    //                         {
    //                             cout << 'R';
    //                             c2--;
    //                         }
    //                         else cout << 'H';
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     else
    //     {
    //         puts("NO");
    //     }
    // }
    int m;
    string a;
    string ans;
    cin >> m >> a;
    int n = 0, s = 0, e = 0, w = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i] == 'E')
            e++;
        else if (a[i] == 'S')
            s++;
        else if (a[i] == 'N')
            n++;
        else
            w++;
    }
    // 特判00

    // if((n == 1 && s == 1) || (w == 1 && e == 1))
    // {
    //     puts("NO");
    //     return ;
    // }
    if (n == 1 && s == 1 && w == 1 && e == 1)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 'N')
                cout << 'H';
            else if (a[i] == 'S')
                cout << 'H';
            else
                cout << 'R';
        }
        cout << endl;
        return;
    }
    int r = 0, h = 0;
    if ((n != s && (n + s) % 2 != 0) || (w != e && (w + e) % 2 != 0))
        puts("NO");
    else
    {
        int ce = e / 2, cs = s / 2, cn = n / 2, cw = w / 2;
        // 然后就每一个都输出一半
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 'E')
            {
                if (ce)
                {
                    ans += 'R';
                    ce--;
                    r++;
                }
                else
                    {
                        ans += 'H';
                        h++;
                    }
            }
            else if (a[i] == 'S')
            {
                if (cs)
                {
                    ans += 'R';
                    cs--;
                    r++;
                }
                else
                    ans += 'H', h++;
            }
            else if (a[i] == 'N')
            {
                if (cn)
                {
                    ans += 'R';
                    cn--;
                    r++;
                }
                else
                    ans += 'H', h++;
            }
            else
            {
                if (cw)
                {
                    ans += 'R';
                    cw--;
                    r++;
                }
                else
                    ans += 'H', h++;
            }
        }
        if(h && r) cout << ans << endl;
        else puts("NO");
    }
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