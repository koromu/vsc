#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int N = 110, INF = 0x3f3f3f3f;
vector<int> g[N * N];// 存边
int dist[N]; // 存一个距离
bool st[N];// 点是否被访问过
int level[N];//
int w[N][N];
int n, m;
int dijkstra(int l, int r)
{
    // 每一个等级在l ~ r之间
    for(int i = 0 ; i <= n ; i ++) 
    {
        dist[i] = INF;
        // 注意我们要多次djkstra
        st[i] = false;
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;

    q.push({0, 0});// 首先合法的就是从
    dist[0] = 0;
    
    // 第一个是当前花的钱, 第二个是当前的点
    while(q.size())
    {
        auto t = q.top(); q.pop();
        int id = t.second;
        if(st[id]) continue;
        st[id] = true;
        for(auto ne : g[id])
        {
            if(dist[ne] > dist[id] + w[id][ne])
            {
                if(level[ne] >= l && level[ne] <= r)// 否则这条路不用走了
                {
                    dist[ne] = dist[id] + w[id][ne];
                    q.push({dist[ne], ne});
                }
                // cout << ne << " " << dist[ne] << endl;
            }
       }
    }
    return dist[1];
}
int main()
{
    cin >> m >> n;// 可以接受的最大的等级差距, 物品的总数
    memset(w, 0x3f, sizeof w);
    for(int i = 1 ; i <= n ; i ++)
    {
        int p, x;
        cin >> p >> level[i] >> x;// 存下第i个人的等级, 其中我们一定有一个要求就是和酋长交易, 所以我们的等级最多是和酋长的差距在m之内
        // dist[0] = max(dist[0], p);
        // 此时连一条从0到i之间的边, 权值p
        g[0].push_back(i);// 存边
        w[0][i] = min(p, w[0][i]);// 存钱
        for(int j = 1 ; j <= x ; j ++)
        {
            // 然后还可以用这些额外的物品获得主物品
            // 相当于这个物品再加v可以买到主物品
            int t, v;cin >> t >> v;
            g[t].push_back(i);// 因为边权不是1了, 所以用距离矩阵维护
            w[t][i] = min(w[t][i], v);
        }
    }

    // 图已经建好了, 然后是等级关系, 已酋长的等级位中心
    // 范围是最大是m, 那么传入一个范围就好了
    int res = 0x3f3f3f3f;
    for(int i = level[1] - m; i <= level[1]; i ++)
    {
        // cout << res << endl;
        res = min(res, dijkstra(i, i + m));// 枚举每一个区间
    }// 这个之后应该res就好了

    cout << res << endl;
    return 0;
}