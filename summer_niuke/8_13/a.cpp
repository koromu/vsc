#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 510;
string a;
int n;
char w[N][N];
bool f1 = false;
// int p1, p2, p3, p4;
int p1;

void solve()
{
    int m; cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a;
        a = " " + a;
        for(int j = 1 ; j <= m ; j ++)
        {
            if(a[j] == 'x')
            {
                w[i][j] = 'x';
            }else if(a[j] == '.')
            {
                w[i][j] = '.';
            }
            // cout << w[i][j] << " ";
        }
        // cout << "\n";

    }

    int len = 0, kuan = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= m ; j ++)
        {
            if(w[i][j] == 'x')
            {
                p1 = j;

                for(int k = j ; k <= m ; k ++)
                {
                    if(w[i][k] == 'x')
                    {
                        len ++;
                    }
                    // else {
                        f1 = true;
                    //     break;
                    // }
                }
                // if(f1)
                // {
                    break;
                // }
            }
        }
        if(f1) break;
    }
    // cout << len << "\n";
    // cout << p1 << "\n";
    for(int i = 1 ; i <= n ; i ++)
    {
        // cout << w[i][p1] << " ";
        if(w[i][p1] == 'x')
        {
            // cout << i << "\n";
            for(int j = i ; j <= n ; j ++)
            {
                if(w[j][p1] == 'x')
                {
                    kuan ++;
                }
                // else 
                // {
                //     // cout << len << " " << kuan << "\n";
                //     break;
                // }
            }
            // cout << kuan << "\n";
            int gc = __gcd(len, kuan);
            // cout << gc << "\n";
            for(int l = 1 ; l <= kuan / gc ; l ++)
            {
                for(int r = 1 ; r <= len / gc ; r ++)
                {
                    cout << 'x';
                }
                cout << "\n";
            }
            // cout << "\n";
            return;
        }
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