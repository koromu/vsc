#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    string a, b; cin >> a >> b;
    // for(int i = 0 ; i <= a.size() - 1 ; i ++)
    // {
    //     // cout << a[i] << " " << b[0] << "\n";
    //     if(a[i] == b[0] || a[i] == '?')
    //     {
    //         bool f = true;
    //         for(int j = 0 ; j <= b.size() - 1 ;)
    //         {
    //             if(a[i + j] == b[j]|| a[i + j] == '?')
    //             {
    //                 continue;// 如果a是？，或者和b相同
    //             }
    //             else
    //             {
    //                 f = false;
    //                 break;// 如果a不是？并且和b不相同
    //             }
    //         }
    //         // 如果出来了， 说明
    //         if(f)
    //         {
    //             cout << "YES\n";
    //             // cout << i - 1 << "\n";
    //             for(int k = 0; k <= i - 1 ; k ++)
    //             {
    //                 if(a[k] == '?') cout << 'a';
    //                 else cout << a[k];
    //             }
    //             cout << b;
    //             // cout << b.size();
    //             for(int k = b.size() + i; k <= a.size() - 1 ; k ++)
    //             {
    //                 if(a[k] == '?') cout << 'a';
    //                 else cout << a[k];
    //             }
    //             cout << "\n";
    //             return;
    //         }
    //     }
    // }
    int j = 0; 
    for(int i = 0 ; i <= a.size() - 1 ; i ++)
    {
        if(a[i] == b[j] || a[i] == '?')
        {
            j++;
            if(a[i] == '?') a[i] = b[j - 1];
            if(j == b.size())
            {
                cout << "YES\n";
                for(int k = 0 ; k <= i ; k ++)
                {
                    cout << a[k];
                }
                // cout << a ;
                for(int k = i + 1 ; k <= a.size() - 1 ; k ++)
                {
                    if(a[k] == '?') cout << 'a';
                    else cout << a[k];
                }
                cout << "\n";
                return;
            }
        }
    }
    // if(j = b.size())
    // {
    //     cout << "YES\n";
    //     cout << a << "\n";
    // }
    // else 
    cout << "NO\n";
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