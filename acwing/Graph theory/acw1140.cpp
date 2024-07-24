#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 110;

int mp[N][N];
bool st[N];// 这个点在不在这个生成树中
int dist[N];// 某一个点到这个生成树的最短距离

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            scanf("%lld", &mp[i][j]);

    // 存好了图然后

    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    // 因为1号点就是要到的点, 所以距离就是0
    dist[1] = 0;
    for(int j = 1 ; j <= n ; j ++)
    {
        int pos = -1;
        for(int i = 1 ; i <= n ; i ++)
        {
            // 先找到一个最小的, 没有被取出过的点, 或者当前这个点的距离还要更小一点
            if(pos == -1 || dist[i] < dist[pos])
                if(!st[i])
                    pos = i;
        }
        // 找到了这个不在连通块的点中距离最小的点
        res += dist[pos];// 加上这个距离
        st[pos] = true;// 这个点标记成去过了
        // 然后尝试用这个点更新别的点的距离
        for(int i = 1 ; i <= n ; i ++)
        {
            if(mp[pos][i])
                dist[i] = min(dist[i], mp[pos][i]);
        }
    }
    cout << res << endl;
    return ;
}


signed main()
{
    int _ = 1; 
    // cin >> _;
    while(_--) solve();
    return 0;
}