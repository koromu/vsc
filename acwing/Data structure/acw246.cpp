#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;
typedef long long ll;
const int N = 500010;
// 两个操作在区间上都加上一个数
// 求区间的最大公约数
// 但是区间加上一个数的话, 有点麻烦, 一个简单的想法就是用差分数组
// 就可以进行单点修改

// 那么差分数组怎么计算最大公因数呢
// 数组中变成了x1 - 0, x2 - x1, x3 - x2 ......
// 原本要算出gcd(x1, x2, x3, x4......)
// 现在没有了x1, x2, x3... (再区间求和就太慢了)
// 所以需要发现gcd(x1, x2) = gcd(x1, x1 - x2);
// 也就是直接用差分数组中的元素就可以求出最大公因数
// 但是注意这个式子的通式是
//gcd(xl, xl+1, xl+2, ..., xr) = gcd(xl, xl+1 - xl, ... , xr - xr-1)
// 所以我们需要维护一个xl, 也就是差分数组的前缀和最后再使用询问操作查出query(1, 1, l), 虽然只会用到其中的一个sum操作

ll w[N];

struct Node{
    int l, r;
    // 所以对于一个区间需要记录什么呢?
    // 首先是这个数本身, 在这里存的是一个差分数组
    // 然后还需要存下最大公因数, 那么最大公因数怎么求呢, 需要的是子区间的最大公因数
    ll sum, gcd;
}tr[N * 4];// 线段树是由常常需要维护的数据

void pushup(Node &u, Node &l, Node &r)
{
    // 使用子节点的值更新自己
    u.sum = l.sum + r.sum;
    u.gcd = __gcd(l.gcd, r.gcd);
}

void modify(int u, int x, ll v)
{
    // 是在修改一个差分数组, 所以是单点修改, 每次增加减少整个区间的值就是修改两个点
    if(tr[u].l == x && tr[u].r == x)// 找到了这个点的话, 那么直接把这个点的值改掉
    {
        tr[u].sum += v;
        tr[u].gcd += v;
    }
    else{
        // 判断一下这个点是在左边还是在右边
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid + 1 <= x) modify(u << 1 | 1, x, v);// 在右区间
        else if(mid >= x) modify(u << 1, x, v);// 在左区间
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);// 修改了单点的话, 就可以用子节点的信息更新自己的信息
    }// 用左右已经修改好的区间, 修改这个u区间
}

Node query(int u, int l, int r)
{
    // 所以查询一个区间, 可能需要创建一个新的区间
    // 如果这个区间被包含了, 那么直接返回这个区间就可以了
    if(tr[u].l >= l && tr[u].r <= r) return tr[u];// 返回这个区间
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        // 判断左右区间是不是需要递归
        if(l > mid) return query(u << 1 | 1, l, r);
        // 如果目标的左边界在mid的右边的话, 说明只需要看右区间就可以了, 注意右区间没有mid, 所以等于mid的话再左区间
        else if (mid >= r) return query(u << 1, l, r);
        else{
            // 说明左右两边都需要查询
            Node tmp;
            Node left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
            // 得到的是左右区间中在l~r的部分, 这就是一直传入l和r的原因
            pushup(tmp, left, right);
            // 这个步骤就是为了求出一个不规则区间的数据区间tmp
            return tmp;// 返回一个区间, 这个区间可能是不规则的
        }
    }
}

void build(int u, int l, int r)
{
    // 当已经是子节点的话
    tr[u] = {l, r};
    if(l == r)// 传入的这个l和r就是u区间的l和r
    {
        // 就可以存下这个v了
        tr[u].gcd = tr[u].sum = w[l] - w[l - 1];
    }
    else
    {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);// 用子节点的信息, 更新一下这个节点
    }
}


int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++) cin >> w[i];

    build(1, 1, n);// 先从建树开始

    char op[2];
    int x, y;
    for(int i = 0 ; i < m ; i ++)
    {
        cin >> op >> x >> y;
        if(op[0] == 'Q')
        {
            // 回答问题需要使用到目标区间的数据, 所以需要新建一个目标区间, 然后再计算
            // 查询l到r区间的最大公因数
            // 需要知道w[l], 但是为什么不能直接使用w[l]呢, 因为可能发生了修改操作, 所以不能直接使用
            Node left = query(1, 1, x);// 得到左右区间端点的点, 然后用左端点区间中的w[l], 和l + 1 ~ r中的最大公因数再取一个最大公因数就可以了
            Node right({0, 0, 0, 0});// 初始是这个, 如果问的是一个一个点的话, 那么直接就是这个区间的值就是了
            // 不需要和后面的区间的, 也就是计算一下区间的边界问题
            if(x + 1 <= y) right = query(1, x + 1, y);
            cout << abs( __gcd(left.sum, right.gcd) ) << endl;// 因为最大公因数可能是个负数, 所以取绝对值
        }
        else{
            ll v;cin >> v;
            modify(1, x, v);
            if(y + 1 <= n) modify(1, y + 1, -v);// 单点修改差分数组
            // 差分数组的特性, 修改的如果是整个区间的话, 就不需要在末尾修改值了, 因为不会影响其他的值了!!!
            // 方法就是判断这个y是不是数组的末尾元素 
        }
    }

    return 0;
}