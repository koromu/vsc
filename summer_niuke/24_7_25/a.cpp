#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1e6 + 10;

int fa[N];
int w[N];
int sz[N];

int find(int x)
{
    if(x != fa[x]) 
    {
        // 说明要找这个fa的祖宗节点
        int tmp = fa[x];
        fa[x] = find(fa[x]);
        // int tmp = find(fa[x]);
        // w[tmp] = w[tmp] + w[x];
        sz[x] += sz[tmp];
    }
    return fa[x];
}


void solve()
{
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        fa[i] = i;
        w[i] = 0;
        sz[i] = 0;
    }

    for(int i = 1 ; i <= n - 1 ; i ++)// n - 1条边
    {
        int a, b, c; cin >> a >> b >> c;
        int xx = find(a), yy = find(b);// a -> b
        // 找到这两个点的祖宗节点, 
        sz[b] = sz[a] + 1;// 长度加1了
        w[xx] = max(w[xx], w[yy] + sz[yy]);
        fa[yy] = xx;
        cout << w[c] << " ";
        // find(b);
    }// 合并完成了
    cout << endl;
    // for(int i = 1 ; i <= n ; i ++) find(i);
    // for(int i = 1; i <= n ; i ++)
    //     cout << w[i] << " ";
    // cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
     cin >> _;
    while(_--)
    {
        solve();
    }
}