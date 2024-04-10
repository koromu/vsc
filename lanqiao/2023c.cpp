#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 15;
int n; // n最大是10阐释考虑直接暴力

struct ph
{
    int t, d, l;
} phs[N];

bool cmp(ph a, ph b)
{
    return a.t < b.t;
}

// int t[N], d[N], l[N];
bool st[N];
bool flag;

void init()
{
    for (int i = 0; i < N; i++)
        st[i] = false;
}

void dfs(int u, int time)
{
    if (u == n)
        flag = true;

    for (int i = 1; i <= n; i++)
    {
        int t = phs[i].t, d = phs[i].d, l = phs[i].l;
        if (/*t <= time && */ !st[i] && time <= t + d && !flag)
        // 最终错点, 发现是这个时间, 每个飞机可以等, 而不一定非要直接找一个飞机, 所以遍历下一架飞机的时候, 可以直接把时间更新成下一个飞机的到达时间, 因为这个代码会遍历所有的情况, 比较暴力的
        {
            st[i] = true;
            dfs(u + 1, max(t, time) + l);
            st[i] = false;
        }
    }
}

void solve()
{
    cin >> n;
    flag = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> phs[i].t >> phs[i].d >> phs[i].l;
    }
    for (int i = 1; i <= n; i++)
    {
        init();
        st[i] = true;
        if (!flag)
            dfs(1, phs[i].t + phs[i].l);
    }
    if (flag) // 当前是从第1个, 花费时间是0,
    {
        puts("YES");
    }
    else
        puts("NO");
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}