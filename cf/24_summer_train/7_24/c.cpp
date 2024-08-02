#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 210;
int p[N];

struct edge{
    int a, b, w;
}edges[N];


int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x]; 
}

bool cmp(edge i, edge j)
{
    return i.w < j.w;
}


void solve()
{
    int n, k; cin >> n >> k;
    // for(int i = 1 ; i <= n ; i ++)// 每个点都有一个集合
    //     p[i] = i;

    // for(int i = 1 ; i <= k ; i ++)
    // {
    //     cin >> edges[i].a >> edges[i].b >> edges[i].w;
    // }

    // sort(edges + 1, edges + 1 + k, [](edge a, edge b){return a.w < b.w;});

    // // 然后取出最小的边, 然后根据这个
    // int ans = 0;
    // for(int i = 1 ; i <= k ; i ++)
    // {
    //     int a = edges[i].a, b = edges[i].b, w = edges[i].w;
    //     int pa = find(a), pb = find(b);
    //     if(pa != pb)
    //     {
    //         p[pa] = pb;
    //         ans += w;
    //     }
    // }
    
    cout << true + true << endl;
    cout << true + false << endl;
    cout << false + false << endl;

}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}