#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;
typedef pair<int, int> pii;
const int N = 510, INF = 0x3f3f3f3f;
vector<int> g[N * N];// 存边
// 权值都是1
int dist[N]; // 存一个距离
bool st[N];// 点是否被访问过
// 每趟车子上去之后就可以到这个站台之后的所有站台
// 所以前面的车站可以连一条向后面的边, 这条边就是乘坐一趟车
// 依次建好了一个图, 然后再图中从1 到 n的最短路即可

int m, n;
string s;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii , vector<pii>, greater<pii>> q;

    dist[1] = 0;
    q.push({0, 1});

    while(q.size())
    {
        auto t = q.top(); q.pop();
        int id = t.second;
        if(st[id]) continue;
        st[id] = true;

        for(auto ne : g[id])
        {
            if(dist[ne] > dist[id] + 1)
            {
                dist[ne] = dist[id] + 1;
                q.push({dist[ne], ne});
            }
        }
    }
    // 更新完了
}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m + 1 ; i ++)
    {// 最多每n * n条边
        // 然后每一个点往后连一条边
        getline(cin, s);
        int w[N];
        stringstream ss(s);// 高级玩意
        int tmp, idx = 1;// 把每一个车站按顺序存到w
        while(ss >> tmp) w[idx++] = tmp;
            // 当ss里面还有输入的时候
        for(int j = 1 ; j <= idx - 1 ; j ++)
            for(int k = j ; k <= idx - 1; k ++)
                g[w[j]].push_back(w[k]);// 连一条j 指向 k的边
    }    

    // 所有的边全部存下来了

    // 然后从1开始做一遍dijkstra
    dijkstra();

    if(dist[n] == INF) puts("NO");
    else printf("%d\n", max(dist[n] - 1, 0));
    return 0;
}