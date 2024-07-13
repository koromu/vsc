#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

// #define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 1010;

int f[N][N];// 当前再第i个，能力值为j的最小步数
int v[N], a[N], b[N];


signed main()
{
    memset(f, 0x3f, sizeof f);
    int n; cin >> n;
    int maxv = 0;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> v[i];
        maxv = max(maxv, v[i]);
    }
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];
    for(int i = 1 ; i <= n ; i ++) 
    {
        cin >> b[i];
        maxv = max(maxv, b[i]);
    }
    // cout << "maxv :" <<  maxv << endl;
    f[1][v[1]] = f[0][v[1]] = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = v[i] ; j <= maxv ; j ++)
        {
            // if(f[i-1][j] != 0x3f3f3f3f)
            // // // 不选
            // {
                f[i][j] = f[i-1][j];
                // cout << "b[i] : " <<  b[i] << endl;
                if(j >= b[i])
                {
                    f[i][j] = min(f[i][j], f[i][j - b[i]] + a[i]);
                    // cout << "i :" << i << " j : " << j << " " << f[i][j] << endl;
                }
        // }
        }
    }
    int ans = INT_MAX;
    for(int i = n ; i <= 10 ; i ++)
        for(int j = v[n] ; j <= maxv ; j ++)
        {
            ans = min(f[i][j], ans);
            // cout << "n :" << n << " i : " << i << " " << f[n][i] << endl;
        }
    // cout << endl;
    // cout << 0xffffffff << " " << 0x3f3f3f3f << endl;
    if(ans == INT_MAX || ans == 0x3f3f3f3f) puts("-1");
    else
        cout << ans << endl; 
    return 0;
}
