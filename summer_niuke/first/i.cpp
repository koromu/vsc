// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <queue>

// #define int long long
// using namespace std;
// typedef pair<int, int> pii;

// const int N = 100010;

// char mp[N][N];
// int cnt[4][N][N];

// int dfs()
// {
//     // 搜索每一个点
// }

// signed main()
// {
//     int n, m; cin >> n >> m;
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         cin >> mp[i + 1];
//     }
//     // 每个点有上下左右,

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define PII pair<int, int>
// #define l first
// #define r second
const int N = 1e3 + 5, M = 0;
int n, m, dp[N][N][4], id[N][N][4], used[N][N][4], tag = 1, cnt = 1;
string s[N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
map<char, array<int, 4>> mp{
    {'-', {1, 0, 2, 3}},
    {'|', {0, 1, 3, 2}},
    {'/', {3, 2, 1, 0}},
    {'\\', {2, 3, 0, 1}}};
// 标记光源射出方向
vector<array<int, 3>> path;

PII dfs(int x, int y, int dir)
{
    if (x < 1 or y < 1 or x > n or y > m)
    {
        return {0, 0};
    }
    if (dp[x][y][dir] and id[x][y][dir])
    {
        tag = id[x][y][dir];// id
        return {dp[x][y][dir], 0};// 如果有的话就会直接返回这个值, 不用再搜索了
    }
    if (id[x][y][dir] == tag)
    {
        // 环
        return {0, 1};
    }
    id[x][y][dir] = tag;
    int ndir = mp[s[x][y]][dir];// 反射的方向
    int nx = x + dx[ndir], ny = y + dy[ndir];// 反射后会到的点
    auto [res, flag] = dfs(nx, ny, ndir);// 然后直接dfs, dfs中的参数是, 当前点的坐标和光从哪个方向射进来的
    if (dir != ndir)// 如果反射后得方向和当前方向不同, 也就是确实是碰到反射了, 而不是穿过去了
    { // rejected
        dp[x][y][dir] = !count(used[x][y], used[x][y] + 4, tag);// dp存的是步数
        used[x][y][dir] = tag;
    }
    id[x][y][dir] = tag;
    if (flag)
        path.push_back({x, y, dir});
    return {dp[x][y][dir] += res, flag};
}


void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        string dir;
        cin >> x >> y >> dir;
        int k = 3;
        if (dir[0] == 'a')
            k = 0;
        else if (dir[0] == 'b')
            k = 1;
        else if (dir[0] == 'l')
            k = 2;
        x += dx[k], y += dy[k];
        tag = ++cnt;
        auto [ans, flag] = dfs(x, y, k);// k是光的方向
        cout << "tag : " << tag << endl;
        if (flag)
        {
            for (auto [l, r, d] : path)
            {
                dp[l][r][d] = ans;// 这个数组是记忆的数组
            }
            path.clear();
        }
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}