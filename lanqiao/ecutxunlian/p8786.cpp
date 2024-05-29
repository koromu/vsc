#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <math.h>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 110, M = 2 * N, mod = 1e9 +7;

int dp[N][N][M];// dp[i][j][k]表示, 进行了看了i次花, 加了j次酒, 剩余k的酒
// 所以枚举n + m 次
// 对于一次操作, 有两种选择, 加酒或者看花
// 如果还有加酒的次数, 那么dp[i][j][k] += d[i][j - 1][k / 2];
// 如果还有看花的次数, 那么dp[i][j][k] += d[i - 1][j][k + 1];
// 所以i和j从小到大枚举, k也可以从小到大枚举
signed main()	
{
    int n, m; cin >> n >> m;
    dp[0][0][2] = 1;
    for(int i = 0 ; i <= n ; i ++)
    {
        for(int j = 0 ; j <= m ; j ++)
        {
            for(int k = 2 * n ; k >= 0 ; k --)
            {
                if(i >= 1 && k % 2 == 0)
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k / 2]) % mod;
                if(j >= 1)
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k + 1]) % mod;
            }
        }
    }

    cout << dp[n][m - 1][1] % mod << endl;// 因为最后必须是花, 而且剩余的酒是0, 所以
    return 0;
}