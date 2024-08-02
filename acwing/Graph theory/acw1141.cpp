#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 110, M = 210;

int p[N];
int n, k;


int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

struct edge{
    int a, b, w;
}edges[M];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int kruskal()
{
    int res = 0;

    for(int i = 1 ; i <= k ; i ++)// 从小到大选边
    {
        int x = edges[i].a, y = edges[i].b, w = edges[i].w;
        int fa = find(x), fb = find(y);
        
        if(fa != fb)
        {
            // res += w;
            p[fa] = fb;
        }
        else res += w;
    }

    return res;
}

void solve()
{
    // 因为我们要这个网络之中的流畅度最高, 也就是值越小
    // 我们要这些点都在的集合之中值最小的情况, 也就是最小生成树
    // 首先我们已知了这个原本的图的边和点, 然后为了这个点都在这个图中, 我们要删除一些边

    // 要删除元素最大, 那么也就是保留元素最小, 所以我们只留最短的边的情况且图连通, 所以就是求最小生成树的权值
    // 然后用总权值减去最小生成树的权值, 就是答案
 
    cin >> n >> k;
    int a, b, w;
    int tot = 0;

    for(int i = 1 ; i <= n ; i ++) p[i] = i;

    for(int i = 1 ; i <= k ; i ++)
    {
        cin >> a >> b >> w;
        // p[i] = i;
        // tot += w;
        edges[i] = {a, b, w};
    }

    sort(edges + 1, edges + 1 + k, cmp);

    // cout << tot - kruskal() << "\n";
    cout << kruskal() << "\n";

    return ;
}


signed main()
{
    int _ = 1; 
    // cin >> _;
    while(_--) solve();
    return 0;
}