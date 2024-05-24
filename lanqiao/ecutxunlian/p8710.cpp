#include <iostream>
#include <set>

using namespace std;
typedef pair<int, int> pii;// 存点的下标
typedef long long ll;

const int N = 100010;

int h[N];// 并查集数组
int w[N];// 每一个点信息内容
int tag[N];
int n, m;
int find(int x)
{
    if(h[x] != x) h[x] = find(h[x]);
    return h[x];
}

void mg(int a, int b)
{
    int x = find(a), y = find(b);
    // 在合并之前, 先把标记给处理一下, 要不然以后就找不到标记了, 因为根节点就不见了
    for(int i = 1; i <= n ; i ++)
    {
        w[i] += tag[find(i)];// 得这个父节点有标记才需要加上标记
    }
    for(int i = 1 ; i <= n ; i ++) tag[i] = 0;
    h[x] = y;// 把a接到b上面去
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n ; i ++){
        h[i] = i;
    }

// 编号1 ~ n
    int op, a, b;
    ll ans = 0;
    for(int i = 0 ; i < m ; i ++){
        cin >> op >> a >> b;
        if(op == 1)
        {
            // 连接操作, 把a, 和b合并起来, 感觉还要维护一个并查集大小数组
            if(find(a) != find(b))
                mg(a, b);
            // 如果不在一个集合中才需要合并
        }
        else
        {
            int x = find(a);// 把这个节点上的所有的点都加上b
            // 所以就可以在这个节点的根节点上存一个标记, 然后每次询问就更新一下所有的根节点上有数字的点, 再减少一点复杂度, 在合并之前我们都可以把这个父节点的标记变大
            tag[x] += b;// 根节点所在的集合全部加上b
        }
    }
    // 最后可能会剩下来, 那种不需要合并的, 但是标记一直打的那种
    // 然后还会有一直加标记的, 不合并的
    // 共同点就是不需要合并, 那么还是可以找到标记的, 所以可以直接遍历一遍
    for(int i = 1; i <= n ; i ++)
    {
        w[i] += tag[find(i)];// 找到这个父节点的标记
    }
    for(int i = 1; i <= n ; i ++)
    {
        cout << w[i] << " ";
    }
}
