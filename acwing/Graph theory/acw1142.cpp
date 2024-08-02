#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 310, M = 8010;

int p[N];
int n, m;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

struct edge{
    int a, b, w;
}e[M];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}


void solve()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++) p[i] = i;
    for(int i = 1 ; i <= m ; i ++)
    {
        int a, b, w; cin >> a >> b >> w;
        e[i] = {a, b, w};
    }

    sort(e + 1, e + 1 + m, cmp);

    int res = 0, c = 0;
    for(int i = 1 ; i <= m ; i ++)
    {
        int a = e[i].a, b = e[i].b, w = e[i].w;
        int fa = find(a), fb = find(b);
        if(fa != fb)
        {
            p[fa] = fb;
            c ++;
            res = max(res, w);// 没有连通的话, 那么就连通起来, 然后更新最大值
        }
    }
    cout << c << " " << res << "\n";
    return ;
}


signed main()
{
    int _ = 1; 
    // cin >> _;
    while(_--) solve();
    return 0;
}