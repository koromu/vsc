#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;
int mp[20][20];

void solve()
{
    for(int i = 1 ; i <= 9 ; i ++)
    {
        string a;
        cin >> a;
        a = ' ' + a;
        for(int j = 1 ; j <= 9 ; j ++)
        {
            mp[i][j] = a[j] - '0';
        }
    }
    for(int i = 1 ; i <= 9 ; i ++)
    {
        for(int j = 1; j <= 9 ; j ++)
        {// 修改1, 1  4, 2  7, 3  2, 4  5, 5  8, 6  3, 7  6, 8  9, 9

            if((i == 1 && j == 1) || (i == 4 && j == 2) || (i == 7 && j == 3) || (i == 2 && j == 4) || (i == 5 && j == 5) || (i == 8 && j == 6) || (i == 3 && j == 7) || (i == 6 && j == 8) || (i == 9 && j == 9))
            {
                mp[i][j] = ((mp[i][j] % 9) + 1);
            }
            // if((i == 1 && j == 1) || (i == 4 && j == 4) || (i == 7 && j == 7) || (i == 1 && j == 7) || (i == 7 && j == 1) || (i == 4 && j == 1) || (i == 7 && j == 4) || (i == 4 && j == 7) || (i == 1 && j == 4) || (i == 7 && j == 4))
            // {
            // if(i == j)
            //     cout << (mp[i][j] % 9 + 1);
            // }
            // else cout << mp[i][j];
            // cout << mp[i][j];
            
        }
        // cout << "\n";
    }
    for(int i = 1 ; i <= 9 ; i ++)
        {
            for(int j = 1 ; j <= 9 ; j ++) cout << mp[i][j];
            cout << "\n";
        }
    return;
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