// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <queue>
// #include <unordered_map>
// #include <vector>

// #define int long long
// using namespace std;
// typedef pair<int, int> pii;
// const int N = 45, P = 998244353;
// int dist[N];
// bool st[N];
// vector<int> v1[N];

// int n, m;

// int ans = 0;

// void bfs(int r)
// {
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         st[i] = false;
//         dist[i] = 0x3f3f3f3f;
//     }
//     priority_queue<pii, vector<pii>, greater<pii>> q;
//     dist[r] = 1;
//     q.push({1, r});
//     while(q.size())
//     {
//         auto t = q.top();
//         int id = t.second, len = t.first;
//         q.pop();
//         if(st[id]) continue;
//         ans = max(ans, len);
//         st[id] = true;
//         for(auto ne : v1[id])
//         {
//             if(dist[id] + 1 < dist[ne])
//             {
//                 dist[ne] = dist[id] + 1;
//                 q.push({dist[ne], ne});
//             }
//         }
//     }
// }

// void solve()
// {
//     cin >> n >> m;
//     for(int i = 1 ; i <= m ; i ++)
//     {
//         int a, b; cin >> a >> b;
//         v1[a].push_back(b);
//         v1[b].push_back(a);
//     }
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         bfs(i);
//     }
//     cout << ans << "\n";
//     return ;
// }

// signed main()
// {
//     int _ = 1;
//     // cin >> _;
//     while(_--)
//         solve();
//     return 0;
// }
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 45;

int n, m;
vector<int> g[N];
int st[N];

int ans = 0;
void dfs(int u, int fa, int len)
{
    ans = max(ans, len);

    for (int i : g[u])
    {
        if(st[i] || i == fa) continue;// 走过了, 或者是来的路
        // for (int i : g[u])
        // {
        //     st[i] = true;
        // }

        for(auto j : g[u]) st[j]++;
        dfs(i, u, len + 1);
        // for (int i : g[u])
        // {
        //     // if (i != fa)
        //     // {
        //         st[i] = false;
        //     // }
        // }
        for(auto j : g[u]) st[j]--;
    }
}

struct du{
    int id, dd;
}dus[N];
map<int, int> mp;

bool cmp( du a, du b )
{
    return a.dd < b.dd;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        // mp[a]++;
        // mp[b]++;
    }

    // int tmp = 1;
    // for(auto i : mp)
    // {
    //     // 得到度数最小的节点
    //     dus[tmp].id = i.first, dus[tmp].dd = i.second;
    //     tmp++;
    // }


    // sort(dus + 1, dus + 1 + n, cmp);

    // int idx = 0;

    for (int i = 1 ; i <= n ; i ++)
    {
        // cout << "id: " << dus[i].id << " dd:" << dus[i].dd << "\n";
        // if(mp[dus[i].dd] == 0)
        // {
        //     mp[dus[i].dd]++;
        //     idx++;
        // }
        // if(idx <= 3)
        //     dfs(dus[i].id, 0, 1);
        // else break;
        dfs(i, 0, 1);
    }
    cout << ans << "\n";

    return 0;
}

