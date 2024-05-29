#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 510;

int w[N][N];
int f[N][N];


signed main()	
{
	int n, m, k; cin >> n >> m >> k;

    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= m ; j ++)
        {
            cin >> w[i][j];
        }
    }
    
    for(int i = 0; i <= n ; i ++)
    {
        for(int j = 0; j <= m ; j ++)
        {
            if(i >= 1 && j >= 1) {
                f[i][j] = f[i-1][j] + f[i][j - 1] - f[i-1][j-1] + w[i][j];
                continue;
            }
            if(i >= 1)
                f[i][j] = f[i-1][j] + w[i][j];
            if(j >= 1)
                f[i][j] += f[i][j-1];
        }
    }

    int ans = 0;
    // 枚举每一个起点和终点
    for(int i = 1; i <= n ; i ++)
    {
        for(int j = 1; j <= m ; j ++)
        {
            for(int x = i; x <= n ; x ++)
            {
                for(int y = j; y <= m ; y ++)
                {
                    int sum = f[x][y] - f[x][j-1] - f[i-1][y] + f[i-1][j-1];// 求出当前矩阵的和
                    if(sum <= k) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}// 70