// // #include <bits/stdc++.h>
// // #define int long long
// // using namespace std;
// // const int N = 2e5 + 10;

// // int n, x, y;

// // vector<int> v1[N];
// // int w[N];

// // int dfs(int u)
// // {   
// //     if(v1[u].size() == 0)
// //     {
// //         // 这个点已经没有叶结点了
// //         return w[u];
// //     }

// //     int tmp = 1e18;
// //     for(auto ne : v1[u])
// //     {
// //         // 取出所有子节点
// //         tmp = min(dfs(ne), tmp);
// //     }

// //     return tmp + w[u];
// // }

// // void solve()
// // {
// //     int n; cin >> n;
// //     for(int i = 1 ; i <= n ; i ++) v1[i].clear();
// //     for(int i = 1 ; i <= n ; i ++) cin >> w[i];
// //     for(int i = 2 ; i <= n ; i ++)
// //     {
// //         int fa; cin >> fa;
// //         v1[fa].push_back(i);
// //     }

// //     cout << dfs(1) << endl;
// // }

// // signed main()
// // {
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);
// //     int _; cin >> _;
// //     while(_--){
// //         solve();
// //     }

// //     return 0;
// // }
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// const int N = 2e5 + 10;

// int n;
// vector<int> v1[N];
// int w[N];
// int dp[N];

// int dfs(int u) {
//     dp[u] = w[u];
//     int cc = 0;
//     for (auto ne : v1[u]) {
//         cc += dfs(ne);
//     }
//     dp[u] += cc;
//     return dp[u];
// }

// void solve() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) v1[i].clear();
//     for (int i = 1; i <= n; i++) cin >> w[i];
//     for (int i = 2; i <= n; i++) {
//         int fa; cin >> fa;
//         v1[fa].push_back(i);
//     }

//     cout << dfs(1) << endl;
// }

// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t; cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7;
const int N = 200010;

vector<int> G[N];
int f[N];

void dfs(int u)
{
    int minn = 0x3f3f3f3f; // 表示v的儿子结点的最大转移值
    for (int ne : G[u])
    {
        dfs(ne);
        minn = min(minn, f[ne]);
    }
    if (minn == 0x3f3f3f3f)
    {
        return;
    }
    if (u == 1)
    {
        f[1] += minn;
        return;
    }
    if (f[u] < minn)
    {
        f[u] = (f[u] + minn) / 2;
    }
    else
    {
        f[u] = minn;
    }
}

void solve()
{
    int n;  
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        G[i].clear();
    }

    for(int i = 2 ; i <= n ; i ++)
    {
        int tmp;
        cin >> tmp;
        G[tmp].push_back(i);
    }  

    dfs(1);
    cout << f[1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}