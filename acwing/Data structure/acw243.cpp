#include <iostream>

using namespace std;

int n, m;

const int N = 100010;

typedef long long ll;

int a[N];// 原数组

ll tr1[N], tr2[N];// 一个d, 一个nd
// 这里需要实现的是区间求和, 区间修改
// 实现区间修改还得是差分数组, 所以使用差分数组中存的还是差分数组, 对这个差分数组进行单点修改和即可实现区间修改
// 那区间求和的话, 差分数组进行前缀和操作的话得到的就是一个数值
// 所以在树状数组中sum(x) 就是原数组中的第x个元素, 所以要求sum( sum(x) ) (l <= x <= r), 当然这样的话是算不出来的

// 所以根据下图的数学推理, 得出了一个公式, 公式中的两个小分式体现出了前缀和的形状, 所以我们才使用树状数组

int lowbit(int x)
{
    return x & -x;
}

void add(ll tr[], int x, ll y)// 因为我们两个数组都用这个函数, 所以可以传入这个数组的引用
{
    // 第i个差分数组加y
    for(int i = x ; i <= n ; i += lowbit(i))
    {
        tr[i] += y;// 这就是修改操作
    }
}

ll sum(ll tr[], int x)
{
    ll res = 0;
    for(int i = x ; i ; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];

    for(int i = 1 ; i <= n ; i ++)
    {
        add(tr1, i, a[i] - (ll)a[i - 1]);
        add(tr2, i, (a[i] - (ll)a[i - 1]) * i);
    }

    // 建好了树, 然后直接可以开搞了

    for(int i = 0 ; i < m ; i ++)
    {
        char op[2];
        int l, r;
        cin >> op >> l >> r;
        if(op[0] == 'C')
        {
            int x;cin >> x;
            add(tr1, l, x);
            add(tr1, r + 1, -x);
            add(tr2, l, (ll)x * l);
            add(tr2, r + 1, -x * (ll)(r + 1));
        }
        else
        {
            // 根据公式得到
            cout << (sum(tr1, r) * (r + 1) - sum(tr2, r)) - (sum(tr1, l - 1) * l - sum(tr2, l - 1) ) << endl;
        }
    }

    return 0;
}