#include<iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 100010;
int n, p;

struct Node{
    int l, r;
    int sum, add, mul;// 乘法标记和加法标记
}tr[N * 4];

int a[N];

void pushdowm(int u)
{   
// 没有标记也可以更新
    // 标记的更新怎么个顺序呢, 因为可能有两个标记都需要更新, 那么考虑一下需要把值更新成怎么个样子
    // 如果有乘有加的话
    tr[u << 1].sum = ((ll)tr[u << 1].sum * tr[u].mul + (ll)tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1)) % p;
    tr[u << 1].add = ((ll)tr[u << 1].add * tr[u].mul + tr[u].add) % p;
    tr[u << 1].mul = ((ll)tr[u << 1].mul * tr[u].mul )% p ;
    tr[u << 1 | 1].sum = ((ll)tr[u << 1 | 1].sum * tr[u].mul + (ll)tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1)) % p;// 非常注意乘法爆int
    tr[u << 1 | 1].add = ((ll)tr[u << 1 | 1].add * tr[u].mul + tr[u].add)%p;
    tr[u << 1 | 1].mul = ((ll)tr[u << 1 | 1].mul * tr[u].mul)%p;
    // 清零两个标记
    tr[u].add = 0, tr[u].mul = 1;

}

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void build(int u, int l, int r)
{
    if(l == r) tr[u] = {l, r, a[l], 0, 1};
    else
    {
        pushdowm(u);
        tr[u] = {l, r, 0, 0, 1};// 记得初始化
        int mid = l + r >> 1;
        build(u << 1 | 1, mid + 1, r);
        build(u << 1, l, mid);
        pushup(u);
    }
}

void modify(int u, int l, int r, int x, int y)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        // 修改的就是这一层的sum和懒标记什么的
        // 假设这一次是要乘上y加上x
        // 那么这些懒标记就如图变化了懒标记就变成了
        tr[u].sum = ((ll)tr[u].sum * y + (ll)(tr[u].r - tr[u].l + 1) * x) % p;    
        tr[u].add = ((ll)tr[u].add * y + x) % p;
        tr[u].mul = ((ll)tr[u].mul * y) % p;
    } 
    else{
        pushdowm(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l) modify(u << 1, l, r, x, y);
        if(mid + 1 <= r) modify(u << 1 | 1, l, r, x, y);// 血的教训, 两边都要修改, 区间如果mid
        pushup(u);
    }
}

ll query(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r)
        return tr[u].sum;
    else 
    {
        pushdowm(u);// 万一没有更新
        ll sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l) sum += query(u << 1, l, r);
        if(mid + 1 <= r) sum = (sum + query(u << 1 | 1, l, r)) % p;
        pushup(u);// 要是上面更新了, 那么下面也就需要更新了
        return sum;
    }
}

int main()
{
    // n 个数字, 最后结果modp
    std::cin >> n >> p;
    for(int i = 1 ; i <= n ; i ++) std::cin >> a[i];

    build(1, 1, n);// n个点的建树

    int m;std::cin >> m;
    while(m--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1)
        {
            int c;
            std::cin >> c;
            // 乘法
            modify(1, l, r, 0, c);// 使用统一的一个函数, 从区间1开始, 把区间l~r的数加上x, 乘上y
        }
        else if(op == 2)
        {
            int c;
            std::cin >> c;
            modify(1, l, r, c, 1);// 加上x乘上1
        }
        else
        {
            cout << query(1, l, r) % p << endl;
        }
    }

    return 0;
}