#include <iostream>

using namespace std;

typedef long long ll;

const int N = 100010;

int n, m;

struct Node
{
    int l, r;
    ll sum, add;// 区间加上一个数, 所以是add标记
}tr[4 * N];

int a[N];


void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

// void pushup(Node &root, Node &left, Node &right)
// {
//     root.sum = left.sum + right.sum;
// }

void pushdown(int u)
{
    if (tr[u].add)// 如果有标记的话才需要更新
    {
        tr[u << 1].sum += (tr[u].add * (ll)(tr[u << 1].r - tr[u << 1].l + 1));// 更新一下子节点, 
        tr[u << 1 | 1].sum += (tr[u].add * (ll)(tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1));// 区间长度加上这个懒标记 , 所以和就是算出其乘积
        tr[u << 1].add += tr[u].add;
        tr[u << 1 | 1].add += tr[u].add;// 把懒标记传递下去
        tr[u].add = 0;//归零懒标记 
        // 乘法就要小心爆int
    }
}

void build(int u, int l, int r)
{
    if(l == r) tr[u] = {l, r, a[r], 0};// 初始是0
    else{
        // pushdown(u);// 在递归之前更新子节点
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);// 再退出递归的时候更新这个节点
    }
}

void modify(int u, int l, int r, int d)
{
    // 区间加上d, 也就是修改一下懒标记, 然后还需要修改一下和
    if(tr[u].l >= l && tr[u].r <= r)
    {
        // 说明被区间包含了, 可以直接更新
        tr[u].sum += (ll)(tr[u].r - tr[u].l + 1) * d;// 乘法注意开ll
        tr[u].add += d;
    }
    else{
        // 在递归之前先pushdown
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, d);// 如果左半边有东西的话, 那么走一下左半边
        if(r > mid) modify(u << 1 | 1, l, r, d);// 如果右半边有数的话, 那么走一下右半边
        pushup(u);
    }
}

ll query(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);// 有可能还没有更新呢
    int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
    if(l <= mid) sum += query(u << 1, l, r);
    if(r > mid) sum += query(u << 1 | 1, l, r);// 左右两边都需要递归
    return sum;
    
}


int main()
{
    cin >> n >> m;
    // 读入长度为n的数组, m条指令
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];

    build(1, 1, n);// 建树

    while(m--)
    {
        char op[2];
        int l, r;
        cin >> op >> l >> r;
        if(op[0] == 'C')
        {
            // 区间修改
            int d; cin >> d;
            modify(1, l, r, d);// 区间加上d
        }
        else 
        {
            cout << query(1, l, r) << endl;
        }
    }

    return 0;
}