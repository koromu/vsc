#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2010;
vector<int> g[N * 2];
double w[N][N];// 点和点之间的倍率
double dist[N];// 每个点到a点的最大倍率, 只要小了, 就要更新, 所以初始成0就好了
bool st[N];
int a, b;
typedef pair<double, int> pdd;

void bfs()
{
    // 从a开始
    priority_queue<pdd> heap;
    dist[a] = 1;
    heap.push({1.0, a});
    // 优先级队列, 存最短距离和点
    while(heap.size())
    {
        // 弹出一个元素
        auto id = heap.top();
        heap.pop();
        if(st[id.second]) continue;// 如果这个点已经被弄好了, 那么就不用再弄了
        st[id.second] = true;
        for(auto ne : g[id.second])
        {
            // 取出这个点的所有临边
            if(dist[ne] < id.first * w[id.second][ne])
            {
                dist[ne] = id.first * w[id.second][ne];
                // if(st[ne]) continue;
                heap.push({dist[ne], ne});
                // st[ne] = true;
            }
        }// 最后dist[b]是最大的倍率
    }
}

int main()
{
    // 问的是a最少要多少钱让b可以得到100元
    // 也就是有一条a到b的边, 然后之间的乘积最大, 也就是每个的乘积最大
    int n, m;
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i ++)
    {
        int x, y, z;cin >> x >> y >> z;
        g[x].push_back(y);// 存下一条边, 然后
        g[y].push_back(x);
        w[y][x] = w[x][y] = max(w[x][y], (double)(100.0 - z) / 100.0);// 存最大的
    }
    cin >> a >> b;
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     for(int j = 1 ; j <= n ; j ++)
    //     {
    //         // if(i !=j)
    //             cout << w[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // 然后bfs一下就行了
    bfs();

    // dist[b]就是到a的最大的倍率
    // for(int i = 1 ; i <= n ; i ++) cout << dist[i] << " ";
    // cout << endl;
    // cout << dist[b] << endl;
    printf("%.8lf\n", 100 / dist[b]);

    return 0;
}