#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int p = 1e9 + 7;
const int N = 1010;
int ans = 0;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n;
bool st[2][N];

void dfs(int u, int x, int y)// 第一个是当前走过的个数, 然后是一个当前的坐标
{
    if(u == n * 2)
    {
        ans = (ans + 1) % p;
        return;
    }
    // for(int i = 0 ; i < 2 ; i ++)
    // {
    //     for(int j = 0 ; j < n ; j ++)
    //     {
    //         if(st[i][j]) cout << 1;
    //         else cout << 0;
    //     }
    //     cout << endl;
    // }
    cout << endl;
    for(int i = 0 ; i < 8 ; i ++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < 2 && ny >= 0 && ny < n && !st[nx][ny])
        {
            // 如果下一个格子是false
            st[nx][ny] = true;
            dfs(u + 1, nx, ny);
            st[nx][ny] = false;// 复原一下
        }
    }
}

int main()
{
    cin >> n;
    if(n % 2 == 0)// 如果是偶数
    {
        for(int j = 0 ; j < n / 2 ; j ++)
        {
            st[0][j] = true;
            dfs(1, 0, j);// 每一个点都有可能是起点
            st[0][j] = false;
        }
        ans = ans * 4 % p;
    }
    else
    {
        for(int j = 0 ; j < n / 2 ; j ++)
        {
            st[0][j] = true;
            dfs(1, 0, j);// 每一个点都有可能是起点
            st[0][j] = false;
        }
        ans = ans * 4 % p;
        st[0][n/2] = true;
        dfs(1, 0, n / 2);
        st[0][n/2] = false;
        
        st[0][n/2] = true;
        dfs(1, 0, n / 2);
        st[0][n/2] = false;
    }

            // 记录一下, 一个格子, 还有当前的格子
    cout << ans << endl;
    return 0;
}