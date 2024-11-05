#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 1010;
int M[N][N];
int n;

void solve()
{
    cin >> n;
    int maxv = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
        {
            cin >> M[i][j];
            maxv = max(maxv,M[i][j]);
        }
        // cout << "\n";

    }
    int ans[N] = {0};
    for(int i = 1 ; i <= n ; i ++)
    {
        // int tmp = M[i][i + 1];
        int tmp = (1 << 31 - 1);
        for(int j = i ; j <= n ; j ++)
        {
            if(i != j)
                tmp = (tmp & M[i][j]);
        }
        ans[i] = tmp;
        cout << tmp << " ";
    }
    
    // for(int i = 1 ; i <= n ; i ++) cout << ans[i] << " ";
    // cout << "\n";

    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     for(int j = 1 ; j <= n ; j ++)
    //     {
    //         if(i == j) cout << "0 ";
    //         else
    //             cout << (ans[i] | ans[j]) << " ";
    //     }
    //     cout << "\n";
    // }
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