#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 200010;

int n, pb, ps;
ll k;
ll ans;
ll w[N], ne[N];
bool st[N];
void dfs(int u, ll now, int po)
{
    //分别传入分数和当前剩余回合数,以方便直接乘以分数, 还有当前的位置
    if(u == 0)
    {
        ans = max(ans, now);//如果已经等于回合数了, 那么就更新答案
        return;
    }
    // cout << "now :" << now << endl;
    now += w[po];//计算如果在这一个格子和去下一个格子的分数
    st[po] = true;
    ans = max(ans, now + w[po] * (u - 1));
    // dfs(u - 1, now, po);//退出来了也不用恢复, 因为这一步是确认的, 主要是第三个参数, 当前的位置是要确认的
    if(!st[ne[po]]) dfs(u - 1, now, ne[po]);
}

void solve()
{
    cin >> n >> k >> pb >> ps;
    // memset(ne, 0, sizeof ne);
    // memset(w, 0, sizeof w);
    for(int i = 1; i <= n ; i ++) scanf("%d", &ne[i]);
    for(int i = 1 ; i <= n ; i ++) scanf("%lld", &w[i]);
    memset(st, false, sizeof st);
    dfs(k, 0, pb);
    // cout << ans << endl;
    ll res = ans ;
    ans = 0;
    memset(st, false, sizeof st);
    dfs(k, 0, ps);
    // cout << res << endl;
    if(res > ans) puts("Bodya");
    else if(res == ans) puts("Draw");
    else puts("Sasha");
    ans = 0, res = 0;
}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}

