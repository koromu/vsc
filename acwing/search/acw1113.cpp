#include <iostream>

using namespace std;

const int N = 21;

string map[N];
int xa, ya, xb, yb;
int n, m;
int dx[4]= {0, 1, 0, -1};
int dy[4]= {1, 0, -1, 0};
int x, y;
int ans;

void dfs(int x, int y)
{
    for(int i = 0 ; i < 4 ; i ++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if(map[xx][yy] == '#') continue;
        ans ++;
        map[xx][yy] = '#';// 因为这个数组只做一个询问, 所以和用一个状态数组的效果应该是相同的
        dfs(xx, yy);
    }
}

int main()
{
    while(cin >> m >> n, n || m)
    {
        ans = 1;// 初始化的问题
        // n是h, 也就是行
        for(int i = 0 ; i < n ; i ++)
            cin >> map[i];
        
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                if(map[i][j] == '@')
                {
                    x = i, y = j;
                }
            }
        }
        map[x][y] = '#';// 自动加上起点, 所以吧起点也标记一下
        // 存好了图, 找到了起点, 确定一下这个下标是从0开始, 还是1开始, 这里是由我们自己定的
        dfs(x, y);
        cout << ans << endl;
    }

    return 0;
}