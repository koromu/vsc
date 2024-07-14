#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 1010;

int f[N][N];// 当前在第i个，能力值为j的最小步数
int v[N], a[N], b[N];

signed main()
{
    for(int i = 1 ; i <= 1000 ; i ++)
        for(int j = 0 ; j <= 1000 ; j ++)
            f[i][j] = 1e18;

    int n; std::cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        std::cin >> v[i];
    }
    for(int i = 1 ; i <= n ; i ++) std::cin >> a[i];

    for(int i = 1 ; i <= n ; i ++) 
    {
        std::cin >> b[i];
    }
    // cout << "maxv :" <<  maxv << endl;
    f[1][v[1]] = 0;
    for(int i = 1 ; i <= n - 1 ; i ++)
    {
        for(int j = 0 ; j <= 1000 ; j ++)
        {
            if(f[i][j] != 1e18)
            {
                if(j >= v[i + 1]) f[i + 1][j] = min(f[i + 1][j], f[i][j]);
                if(j + b[i] >= v[i + 1]) f[i + 1][min(j + b[i], 1000ll)] = min(f[i + 1][min(j + b[i], 1000ll)], f[i][j] + a[i]);
            }
        }
    }

    int ans = 1e18;
    for(int i = 0 ; i <= 1000 ; i ++)
        ans = min(f[n][i], ans);
            // cout << "n :" << n << " i : " << i << " " << f[n][i] << endl;
    // cout << endl;
    // cout << 0xffffffff << " " << 0x3f3f3f3f << endl;
    if(ans == 1e18) puts("-1");
    else
        cout << ans << endl; 
    return 0;
}
