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
    }

    for(int i = 2 ; i <= n ; i ++)
    {
        int tmp;
        cin >> tmp;
        G[tmp].push_back(i);
    }  

    dfs(1);
    cout << f[i] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}