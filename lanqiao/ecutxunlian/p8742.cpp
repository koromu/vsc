#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;// 存点的下标
typedef long long ll;

const int N = 110, M = 100010;

int w[M];
bool f[N][M];// 表示从前i个中可不可以称出重量是j
// 只问的是重量出现的种类数, 所以可以由不同的砝码称出来
// 最后再遍历一遍得到种类数

int main()
{
    int n;
    cin >> n;
    ll cnt = 0;
    for(int i  = 1 ; i <= n ; i ++) {
        cin >> w[i];
        cnt += w[i];
        f[i][w[i]] = true;
    }
    for(int i = 0 ; i <= n ; i ++) f[i][0] = true;
    for(int i  = 1 ; i <= n ; i ++)
    {
        // 枚举物品, 然后枚举重量
        for(int j = 1 ; j <= cnt; j ++)
        {
            // 重量最大就是砝码重量之和
            f[i][j] = (f[i][j] || f[i-1][j]);// 如果不需要到这里就可以称出来的重量, 那么到这里不选也行
            f[i][j] = (f[i][j] || f[i-1][abs(j - w[i])]);
            if(j + w[i] <= cnt) f[i][j] = (f[i][j] || f[i-1][j + w[i]]);
        }
    }
    ll ans = 0;
    for(int i  = 1 ; i <= cnt ; i ++)
    {
        if(f[n][i]) ans++; 
    }

    cout << ans << endl;
    
    return 0;
}