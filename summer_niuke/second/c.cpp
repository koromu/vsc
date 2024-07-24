#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 2e5 + 10;
string w[3];
int a[N][3];
int f[N][3];
unordered_map<int, int> ha;

void solve()
{
    int n; cin >> n;
    cin >> w[1] >> w[2];
    // cout << w[1] << " " << w[2] << endl;
    // 遍历每一列
    for(int k = 1 ; k <= 2; k ++)
    {
        for(int i = 1 ; i <= n ; i ++)
        {
            if(w[k][i - 1] == 'R')
            {
                a[i][k] = 0;// 0是可以走的, 1是不可以走的, 这样就免去了初始化前面两个格子
            }
            else a[i][k] = 1;
            // cout << a[i][k] << " ";
        }
        // cout << endl;
    }

    // 然后得到了原数组
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= 2 ; j ++)
        {
            if(!a[i - 1][1])// 看这个格子前面的两个格子是否可以走
                f[i][j] = max(f[i][1], f[i - 1][0] + 1);
            if(!a[i - 1][2])
                f[i][j] = max(f[i][2], f[i - 1][1] + 2);
        }
    }

    return ;
}


signed main()
{
    int _ = 1; 
    // cin >> _;
    while(_--) solve();
    return 0;
}