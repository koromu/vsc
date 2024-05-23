#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;
typedef long long ll;

struct Node{
    int l, r;
    ll sum, mul;// 当前区间的的乘积和
}tr[N * 4];

int q, m;

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum * tr[u << 1 | 1].sum % m;
}

void modify(int u, int x, int d)
{
    if(tr[u].l == x && tr[u].r == x)
    {
        tr[u].mul = ( tr[u].mul * d % m), tr[u].sum = d;
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, d);
        else modify(u << 1 | 1, x, d);// ''--/这个单点修改只修改一个区间
        pushup(u);
    }
}

void build(int u, int l, int r)
{
    if(l == r)
    {
        tr[u] = {l, r, 1, 1};
    }
    else
    {
        int mid = l + r >> 1;
        tr[u] = {l, r};
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}// ok

ll query(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r )
    {
        return tr[u].sum;
    }
    else
    {
        ll sum = 1;
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l) sum *= query(u << 1, l, r) % m;
        if(mid + 1 <= r) sum *= query(u << 1 | 1, l, r) % m;
        return sum % m;
    }
}

void solve()
{
    // 对于每个操作, 按时间顺序建树
    // 树中存的是区间的乘积和, 然后在2操作时, 我们就除去第二次操作的乘数, 也就是把这个乘法标记变成1
    memset(tr, 0, sizeof tr);
    cin >> q >> m;
    // cout << q << " " << m << endl;】
    build(1, 1, q);// m个操作
    // 每次询问的话, 1就是把当前位置的乘法标记变成d, 2就是把当前位置的乘法标记变成1, 单点修改
    // 询问就是求区间的乘法
    for(int i = 1 ; i <= q ; i ++)
    {
        int op, d;
        cin >> op >> d;
        // cout << op << endl;
        if(op == 1)
        {
            modify(1, i, d);// 修改第i天的乘法标记
            cout << query(1, 1, m) % m << endl;
        }
        else
        {
            // cout << "i : " << i << endl;
            modify(1, d, 1);// 把第d个改成1, 然后算一下整个区间的乘积和
            cout << query(1, 1, m) % m << endl;
        }
    }
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