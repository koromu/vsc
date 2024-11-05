#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 1010, M = N * N;

int p[M];
int id[N][N];
int ans;
int n, m;// n行, m列
int find(int x)
{
    if(p[x] != x ) p[x] = find(p[x]);
    return p[x];
}

int dx1[2] = {1, -1}, dy1[2] = {0, 0};
int dx2[2] = {0, 0}, dy2[2] = {1, -1};

struct edge{
    int a, b, w;
}edges[2 * M];// 这几个数组的大小可有一些学问
int ce;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void gete()// 一个太神奇的优化, 对于一条边, 只从上到下, 从左到右, 也就是边的起点的编号一定小于边的终点的编号
{// 不能边搜边连边, 一个很简单的就是上面没连起来, 但是下面连起来了, 总之就是先把边找出来, 然后再排序找
    // 对一个点遍历四个方向
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= m ; j ++)
        {
            for(int k = 0 ; k <= 1 ; k ++)
            {
                // if(i + dx1[k] > n || j + dy1[k] > m || i + dx1[k] < 1 || j + dy1[k] < 1) continue;
                if(i + dx1[k] <= n && j + dy1[k] <= m && i + dx1[k] && j + dy1[k])
                {
                    int aa = id[i][j], bb = id[i + dx1[k]][j + dy1[k]];
                    if(aa < bb) edges[ce++] = {aa, bb, 1};
                }
                // if(!st[i][j])
                // {

                    // 如果这个点没有连起来
                    // if(!st[i + dx1[k]][j + dy1[k]] || k == 1 )
                    // {
                        // int f1 = find(id[i][j]), f2 = find(id[i + dx1[k]][j + dy1[k]]);
                        // if(f1 != f2)
                        // {
                        //    p[f1] = f2;
                        // }
                        // ans ++;
                        // std::cout << "ans : " << ans << "\n";
                    // }
                    // st[i][j]++;
                // }
            }// ?莫名其妙报个错, 还要我声明
        }
    }

    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= m ; j ++)
        {
            for(int k = 0 ; k <= 1 ; k ++)
            {
                if(i + dx2[k] <= n && j + dy2[k] <= m && i + dx2[k] && j + dy2[k])
                {
                    int aa = id[i][j], bb = id[i + dx2[k]][j + dy2[k]];
                    // cout << aa << " " << bb << "\n";
                    if(aa < bb) edges[ce++] = {aa, bb, 2};
                }
                // if(!st[i][j])
                // {
                    // // 如果这个点没有连起来
                    // // if(!st[i + dx2[k]][j + dy2[k]] || k == 1 )
                    // // {
                    //     int f1 = find(id[i][j]), f2 = find(id[i + dx2[k]][j + dy2[k]]);
                    //     if(f1 != f2)
                    //     {
                    //        p[f1] = f2;
                    //     }
                    //     ans += 2;
                    // // }
                    //     std::cout << "ans : " << ans << "\n";
                    // st[i][j]++;
                // }
            }
        }
    }
}


void solve()
{
    cin >> n >> m;
    for(int i = 1, t = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++, t ++)
        {
            id[i][j] = t;
            // std::cout << "i :" << i << " j : "  << j << " " << t << "\n";
        }

    for(int i = 1 ; i <= n * m ; i ++) p[i] = i;
    int x1, x2, x3, x4;

    // 点不多的话, 直接给每一个点一个特殊的编号

    while(cin >> x1 >> x2 >> x3 >> x4)
    {
        // 读入之后把这两个点连一条边
        // 如果是纵边那么+1, 要么横边+2
        int f1 = find(id[x1][x2]), f2 = find(id[x3][x4]);
            // st[x1][x2]++, st[x3][x4]++;
        p[f1] = f2;
            // if(x1 != x3)
            // {
                // ans ++;
            // }
            // else ans += 2;
        // cout << "ans : " << ans << "\n";
    }
    // 然后再把没有连起来的点连起来, 优先连纵边, 最后实在不行了再连横边

    gete();

    sort(edges, edges + ce, cmp);

    // for(int i = 0 ; i < ce ; i ++) cout << edges[i].a << " " << edges[i].b << " " << edges[i].w << "\n";

    for(int i = 0 ; i < ce ; i ++)
    {
        int x1 = edges[i].a, x2 = edges[i].b, w = edges[i].w;
        int f1 = find(x1), f2 = find(x2);
        if(f1 != f2)
        {
            p[f1] = f2;
            ans += w;
        }
    }

    std::cout << ans << "\n";

}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

return 0;
}