#include <iostream>
#include <vector>
#include <math.h>
#include <string>

#define int long long

using namespace std;

int f[110][(1 << 6) + 10][(1 << 6) + 10][25];// f[i][j][k][l][m]// 表示当前是第i列, 当前层状态是j, 上一层状态是k, 上上层状态是l, 使用了m匹马的方案数
int a, b, c;  
int mod = 1e9 + 7;
int cnt(int x)
{
    int ans = 0;
    while(x)
    {
        ans ++;
        x -= (x & -x);
    }
    return ans ;
}


signed main()
{
    string a, ans = "";
    cin >> a;
    for(int i = 0; i < a.size(); i ++)
    {
        if(a[i] >= 'a' && a[i] <= 'z')
            ans += a[i] - 'a' + 'A';
        else ans += a[i];
    }
    cout << ans << endl;
    return 0;
}