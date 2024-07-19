#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 1010;
char mp[N + 10][N + 10];
int w[N + 10][N + 10];
pii q[N * N];
int hh = 0, tt = -1;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m; 
void bfs()
{
    // 已经存好了所有的点
    while(hh <= tt)
    {
        // 队列不空
        int xx = q[hh].first, yy = q[hh].second;
        hh++;
        for(int i = 0 ; i < 4 ; i ++)
        {
            int nex = xx + dx[i], ney = yy + dy[i];
            if(mp[nex][ney] == '0' && w[nex][ney] == 1e18 && nex >= 0 && nex < n && ney >= 0 && ney < m)
            {
                w[nex][ney] = w[xx][yy] + 1;
                q[++tt] = {nex, ney};
            }
        }
    }
}

signed main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++)
        cin >> mp[i];
    for(int i = 0; i < n ; i ++)
    {
        for(int j = 0 ; j < m ; j ++)
        {
            w[i][j] = 1e18;
            if(mp[i][j] == '1')
            {
                q[++tt] = {i, j};
                w[i][j] = 0;
            }
        }
    }
    bfs();
    for(int i = 0; i < n ; i ++)
    {
        for(int j = 0 ; j < m ; j ++)
        {
            cout << w[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
