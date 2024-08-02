#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 2010, M = 100010;

int p[N];
int n, m;
int res = 0;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

vector<pair<pair<int, int>, int>> e;

vector<int> g[N];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}

void k()
{
    for(int i = 0 ; i < e.size() ; i ++)
    {
        int u = e[i].first.first, v = e[i].first.second, w = e[i].second;
        int fu = find(u), fv = find(v);
        if(fu != fv)
        {
            p[fu] = fv;
            res += w;
            g[u].push_back(v);
        }
    }
}


void solve()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++) p[i] = i;

    
    for(int i = 1 ; i <= m ; i ++)
    {
        int op, u, v ,w; cin >> op >> u >> v >> w;
        if(op == 1)
        {
            int pu = find(u), pv = find(v);
            p[pu] = pv;
            res += w;
        }
        else if(op == 2)
        {
            e.push_back({{u, v}, w});
        }
    }
    sort(e.begin(), e.end(), cmp);

    k();

    cout << res << "\n";
    return ;
}


signed main()
{
    int _ = 1; 
    // cin >> _;
    while(_--) solve();
    return 0;
}