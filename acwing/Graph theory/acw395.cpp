#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 10010, M = 2 * N;
vector<pair<int, int>> es[N];
int dfn[N], low[N], times;// 时间戳和两个数组
int stk[N], top;// 一个栈，把一个连通分量里的点都压入栈中，然后找完了再全部弹出来
int id[N], dcc_cnt;// id[i]表示点i所在的连通分量，dcc_cnt表示连通分量的个数
bool is_bridge[M];// 可以记录每一条边是不是桥

void tarjan(int u, int from)// 这个点从那个边过来的from
{
    dfn[u] = low[u] = ++times;// 先更新一个时间戳
    stk[++ top] = u;// 先把这个点加到栈里面去

    for(auto ne : es[u])// 遍历所有临边
    {
        if(!dfn[ne.first])// 如果这个点还没被遍历过的话，那么遍历一下这个点
        {
            tarjan(ne.first, u);
            low[u] = min(low[u], low[ne.first]);// 更新这个点的low值
            if(low[ne.first] > dfn[u])
            {
                // 如果这条边的子节点的low值比这个边的父节点的dfn值大，那么说明这个子节点无论如何都到不了父节点的，也就是说这个边是桥
                
            }
            // 这里需要给每条边特俗编号，并且找到一条边就可以找到另一条边，所以需要用两个变量记录
        }

    }

}

void solve()
{
    int n, m; cin >> n >> m;// n点m边
    for(int i = 1 ; i <= m ; i ++) es[i].clear();
    for(int i = 1 ; i <= m ; i ++)
    {
        int a, b ; cin >> a >> b;
        es[a].push_back({b, 0});
        es[b].push_back({a, 0});
    }

    tarjan(1, -1);// 第一个参数

    // 桥的编号怎么办呢

}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}