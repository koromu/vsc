#include <iostream>

using namespace std;
typedef long long ll;
const int N = 500010;

int a[N];

struct Node{
    int l, r;
    int lmax, rmax, tmax, sum;// 前缀和后缀
}tr[N * 4];
// 我们要求的是最大的连续字段和, 一个数字可能为负数
// 我们的线段树可以维护每一个区间的最大值, 但是如果是多个区间那么可能不是连续的, 所以至少要连续, 我们计算每一个区间的从头开始的最大值, 然后可以和前一个区间的到尾巴的最大值相加
// 所以一个区间需要维护一个前缀最大值, 一个后缀最大值
// 然后对于这个区间的最大和也就是子区间的最大后缀加上最大前缀, 所以我们还要记录这个值, 记作tmax, 也就是这个区间的最大子段和
// 于是我们再思考这个前缀最大子段和怎么求的, 难道是前缀和? 在线段树中, 选择致力于用子树推出父节点的值
// 于是我们选择使用子节点的信息推出来
// 思考前缀字段和怎么使用子节点的值算出来, 1.是左区间的字段和, 并没有跨过这个区间 2.跨过了这个区间, 也就是左边整个区间的和, 加上右边的最大前缀和
// 所以为了更快的算出来这个值, 我们选择再维护一个当前区间的和记作sum

// 然后还有一个经典的左右区间
// 然后是各个操作, 要求单点修改, 询问区间的最大连续字段和

void pushup(Node &u, Node &l, Node &r)
{
    // 这个明显需要子节点的信息
    // 这个点的总和就是下两个点的和
    u.sum = l.sum + r.sum;
    u.lmax = max(l.sum + r.lmax, l.lmax);
    u.rmax = max(r.rmax, l.rmax + r.sum);// 后缀和的最大值有两种情况
    u.tmax = max(max(l.tmax, l.rmax + r.lmax), r.tmax);// 可能有三种情况 
}

void modify(int u, int x, int v)
{// 刚好这个x是个下标
    // 如果找到了的话
    if(tr[u].l == x && tr[u].r == x) tr[u].rmax = tr[u].lmax = tr[u].tmax = tr[u].sum = v;
    // 我们修改值就只是修改一个值, 所以先找到那个值
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);// 如果这个坐标在mid左边的话, 那么就找左边的区间, 也就是编号u << 1
        else modify(u << 1 | 1, x, v);// 只要找到了返回以后直接更新父节点就可以了
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
}

Node query(int u, int l, int r)
{
    // 查询的是一个区间的最大连续字段和
    // 如果递归到了一个完全被包含在这个目标区间的区间的话, 那么直接给父节点判断
    if(tr[u].l >= l && tr[u].r <= r ) return tr[u];
    else
    {
        // 如果当前这个区间不被完全包含
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid) return query(u << 1, l, r);// mid比这个区间的右区间还大的话, 那么就只要递归查询左区间
        else if(l > mid) return query(u << 1 | 1, l, r);// 如果mid + 1 比区间左端点还小的话, 也就是比左区间还左的话, 那么就只要递归右区间
        else{
            // 要不然的话就是左右区间都需要递归, 然后还需要合并两个区间
            // 合并两个区间变成一个新的区间, 然后再给上一个区间用来合并
            // 合并这个区间以后我们需要用到这个独特的区间的数据, 所以我们需要存下这四个数据, 然后再给上面的区间
            Node lef = query(u << 1, l, r);
            Node rig = query(u << 1 | 1, l , r);
            // 然后我们额外维护一个u区间
            // 但是这个区间是不存在的, 是一个不完整的区间, 但是合并的过程是使用两个完整的区间的, 不能通过不完整的区间直接使用下标找到两个完整的区间
            // 所以pushup操作需要直接传入节点
            // 这个新的区间我们是需要创建出来的, 但其实只是要这个区间的信息, 所以可以不用存下来, 直接给父区间用就是了
            Node tmp;// 这就是一个区间, 这个区间就是当前区间中游泳的区间, 因为lef和rig就是有用的区间, 最最最根源的话, 这个lef和rig就是
            pushup(tmp, lef, rig);// 更新一下tmp
            // cout << tmp.rmax << " " << tmp.lmax << " " << tmp.tmax << " " << tmp.sum << endl;
            return tmp;
        }
    }
}// 每次更新都是用左子节点和右子节点

void build(int u, int l, int r)
{
    if(l == r) tr[u] = {l, r, a[r], a[r], a[r], a[r]};
    else{
        tr[u] = {l, r};// 要不然能确定的只有这个信息
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        // 出来了之后可以用子节点的信息更新一下自己
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
}


int main()
{
    int n, m;// 长度为N的数列, 和M个询问
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];// 读入每个元素, 非常逆天的是, 因为赋值的时候我直接用了l和r当下标, 然后但是数组中的下标是从0开始的
    // 怎么建树呢?
    build(1, 1, n);// 长度是N

    for(int i = 0 ; i < m ; i ++)
    {
        int k, x, y; cin >> k >> x >> y;
        if(k == 1)
        {
            if(x > y) swap(x, y);
            cout << query(1, x, y).tmax << endl;// 查询x, y的tmax
        }
        else 
            modify(1, x, y);// 在a[x]上加y
    }

    return 0;
}