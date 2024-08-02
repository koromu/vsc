#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

struct edge{
    int x, y;
}el[N * 2], eq[2 * N];

vector<int> v1[N];

int ru[N];
int p[N];
vector<int> lun;
int cq, cl;
int ccq;
int ans;
vector<int> v2[N];


int find(int x)
{
    if(p[x] != x ) p[x] = find(p[x]);
    return p[x];
}

void kruskal()
{
    for(int i = 1 ; i <= cq ; i ++) // 然后遍历所有切边
    {
        int fx = find(eq[i].x), fy = find(eq[i].y);
        if(fx != fy)
        {
            p[fx] = fy;
            v2[eq[i].x].push_back(eq[i].y);
            ans ++;
            ccq ++;
        }
    }
}

bool cmp(edge a, edge b)
{
    return a.x > b.x;
}

bool st[N];
void solve()
{
    // 先把 轮 和 切 边存起来
    // 先建图, 不建 切 边, 然后把论的两点都存起来, 然后判断这些点的入度有没有0
    // 没有0说明确实是都在环里面
    int n, m; cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
    {
        p[i] = i;
    }

    for(int i = 1 ; i <= m ; i ++)
    {
        char op[5];
        int a, b; cin >> a >> b >> op;
        if(op[0] == 'L')
        {
            v1[a].push_back(b);
            v1[b].push_back(a);
            ru[a]++, ru[b]++;
            // 把这两个点放到并查集中
            int fa = find(a), fb = find(b);
            p[fa] = fb;
            lun.push_back(a), lun.push_back(b);
            cl++;
            ans ++;
        }
        else 
        {
            eq[i].x = a, eq[i].y = b;
            cq++;
        }
    }

    for(auto i : lun)
    {
        if(ru[i] < 2)
        {
            cout << "NO\n";
            return;
        }
    }
    sort(eq + 1, eq + 1 + n, cmp);

    // for(int i = 1; i <= cq ; i ++)
    // {
    //     cout << eq[i].x << " " << eq[i].y << "\n";
    // }

    kruskal();



    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     // for(auto ne : v1[i])
    //     // cout << i << " " << ne << "\n";
    //     cout << p[i] << " ";
    // }
    // cout << "\n";
    cout << "YES\n" << ans << "\n";

    for(auto i = 1 ; i <= ccq ; i ++)
    {
        for(auto ne : v2[i])
        {
            cout << i << " " << ne << "\n";
        }
    }
    map<pair<int, int>, bool> mp;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(auto ne : v1[i])
        {
            int x = i, y = ne;
            if(x > y) swap(x, y);
            if(!mp[{x, y}])
            {
                mp[{x, y}] = true;
                cout << x << " " << y << "\n";
                st[x] = st[y] = 1;
            }
        }
    }

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
