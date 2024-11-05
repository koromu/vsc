#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 100005
#define B 133

int i, j, k, n, m, t, fa[N + 50], id[N + 50], vis[N + 50];

vector<tuple<int, int, int>> bian, v;
unordered_map<ll, int> mp;

vector<int> q;

int find(int x) { return (fa[x] == x ? x : fa[x] = find(fa[x])); }

void query()
{
    int i, j, k, tot = q.size();// q里面存的是询问的点
    ll res = 0;// 记录全值
    v.clear();
    for (auto i : q)// 初始化并查集数组, 要用到的点状态初始化成1
    {
        vis[i] = 1;
        fa[i] = i;
    }
    if (tot >= B)
        v = bian;
    else
    {
        for (auto i : q)
            for (auto j : q)
                if (i < j)
                {
                    ll t1 = 1ll * N * i + j;// 将两个键变成一个键
                    if (mp.count(t1))// 查询所有的小边
                        v.push_back({mp[t1], i, j});
                }

        sort(v.begin(), v.end());
    }

    for (auto [w, x, y] : v)
    {
        if (!vis[x] || !vis[y])
            continue;
        x = find(x);
        y = find(y);
        if (x != y)
        {
            res += w;
            fa[y] = x;
            tot--;
        }
    }
    if (tot != 1)
        res = -1;
    cout << res << '\n';
    for (auto i : q)
        vis[i] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for (i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x > y)
            swap(x, y);
        ll t1 = 1ll * N * x + y;// 将两个键变成一个键
        if (!mp.count(t1))// 如果这个边的全职没有存在那么就存进去这个权值
            mp[t1] = z;
        else
            mp[t1] = min(mp[t1], z);// 如果存在那就存更小的那条边
    }
    for (auto [id, w] : mp)
    {
        ll x = id / N, y = id % N;// 遍历map的每条边, 存到vector里面进行排序
        bian.push_back({w, x, y});
    }
    sort(bian.begin(), bian.end());// 克鲁斯卡尔需要的排序
    while (t--)
    {
        int sz;
        cin >> sz;
        q.clear();
        while (sz--)// 处理每次询问, 取出这次询问要用到的点
        {
            cin >> k;
            q.push_back(k);
        }
        query();// 询问操作
    }
}
