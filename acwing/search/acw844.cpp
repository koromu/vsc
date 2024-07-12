#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;

const int N = 110;
int map[N][N];
int len[N][N];// 状态数组
int dx[4] = {-1, 0 ,1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m; 
int bfs()
{
    queue<pii> q;
    q.push({1, 1});
    // 先插入起点，然后再开始宽搜
    while(!q.empty())
    {
        auto t = q.front(); q.pop();// 弹出队头元素
        // 然后扩展这个点
        for(int i = 0 ; i < 4 ; i ++)
        {
            int xx = t.first + dx[i], yy = t.second + dy[i];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && len[xx][yy] == -1 && map[xx][yy] == 0)// 如果没有去过, 并且是能走的
            {
                q.push({xx, yy});
                len[xx][yy] = len[t.first][t.second] + 1;// 这样的话还需要一个距离数组
                // 但是实际可以用一个距离数组代替，一个点只会被走一遍
            }
        }
    }
    return len[n][m] ;
}

int main()
{
    // bfs搜到最短路
    // 需要权重都为1
    memset(len, -1, sizeof len);
    len[0][0] = 0;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
            cin >> map[i][j];

    cout << bfs() + 1 << endl;

    return 0;
}