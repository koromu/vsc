#include <iostream>

using namespace std;
typedef long long ll;
const int N = 200010;
// 操作全都是a的话, 那么最多就是m个东西

struct point
{
    int l, r;
    int v;
} tr[N];

int pushup(int u)
{
    tr[u].v = max(tr[u >> 1].v, tr[u >> 1 | 1].v); // 这里维护的是一个全局的最大值, 所以我们这个u节点需要更新成子节点中最大的一个
}//

void modify(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x)
        tr[u].v = v;// 真正修改就这一行, 下面的只是递归找到这个点
    // 否则就递归
    else
    {
        // 只修改x存在的一边, 所以在修改区间之前, 我们现在判断这个x属于那个区间
        int mid = tr[u].l + tr[u].r >> 1;
        if(x >= mid) modify(u >> 1 | 1, x, v);
        else modify(u >> 1, x, v);
        pushup(u); // 更新一下这个点的数据
    }
}

int query(int u, int l, int r)// 传入目标区间, 然后还有当前节点
{
    // 问的是一个区间的最大值
    // 如果当前节点已经是叶子结点了, 那么直接返回这个点的值就可以了
    if(tr[u].l == tr[u].r) return tr[u].v;
    // 否则就递归找到叶子结点
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;// 接收一下子节点的最大值
    if(mid > l) v = max(v, query(u >> 1, l, r));// 只有当mid在l的右边的时候,我们才能遍历左区间
    if(mid < r) v = max(v, query(u >> 1 | 1, l, r));// 同理可得, 只有当区间在
    return v;// 当前区间的最大值
}

void build(int u, int l, int r)
{
    // 建树就是先递归到最底层, 然后存一下每一个的区间, 然后更新一下两个的值, 但是这棵树是没有初始值的
    tr[u] = {l, r};// 直接存入这区间的坐标, 不一定需要到子树
    if(l == r) return;// 如果到了子节点
    int mid = l + r >> 1;
    build(u >> 1, l, mid), build(u >> 1 | 1, mid + 1, r);
    // pushup(u);// 更新一下当前区间的值;
}


int main()
{
    int m, p;
    cin >> m >> p;
    char op[2];
    int x;
    int n = 0; // 当前这个区间的长度
    build(1, 1, m);// 直接先把一整个树建好, 因为不确定多大, 所以直接最大
    int last = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> op >> x;
        if (op[0] == 'A')
        {
            // 添加一个数
            // 就是在n + 1这个点修改成x
            modify(1, n + 1, (ll)(x + last) % p);
            n++;// 修改一个值不是O(1)的了, 但是有其他的好处
        }
        else
        {
            // 查询一个区间
            last = query(1, n - x + 1, n);// 后L个数就是后x个数, 也就是从 n - x + 1 -> n
            cout << last << endl;
        }
    }

    return 0;
}