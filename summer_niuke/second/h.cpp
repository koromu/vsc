#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define PII pair<int, int>
// #define l first
// #define r second
const int N = 2e5 + 10, M = 0;
int n, x, y;

int dd[4] = {1, 2, 3, 4};// 上下左右
int pre[N][5];// W, A, S, D的前缀和
int C[N][N];


void init()
{
    C[1][0] = C[1][1] = 1;
    for(int i = 2; i <= n ; i ++)
    {
        for(int j = 0 ; j <= i ; j ++)
        {
            if(j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            // cout << C[i][j] << " ";
        }
    }
}

void solve()
{   
    cin >> n >> x >> y;
    string a ; cin >> a;
    a = ' ' + a;
    int ox, oy;
    int _ox, _oy;
    // 有左上, 右上, 左下, 右下
    if(x >= 0 && y >= 0)
    {
        ox = 4, oy = 1;
        _ox = 3, _oy = 2;
    }
    else if(x < 0 && y > 0)
    {
        ox = 3, oy = 1;
        _ox = 4, _oy = 2;
    }
    else if(x <= 0 && y <= 0)
    {
        ox = 3, oy = 2;
        _ox = 4, _oy = 1;
    }
    else if(x > 0 && y < 0)
    {
        ox = 4, oy = 2;
        _ox = 3, _oy = 1;
    }

    // 这下知道了x和y需要的方向
    // 并且找到ox的对位


    // 先找到最少要的
    int cx = abs(x), cy = abs(y);


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
