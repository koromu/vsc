#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 100010;

int n, m;

// 首先肯定是一个差分数组, 然后还有个原数组, 这个差分数组就是存在树状数组中
int tr[N];
int a[N]; // 原数组

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int y)
{
    for(int i = x ; i <= n ; i += lowbit(i))
    {
        // x上加上y, 然后再把要更新的值更新一下
        tr[i] += y;
    }
}

ll sum(int x)
{
    ll res = 0;
    for(int i = x ; i > 0 ; i -= lowbit(i))// 只有知道了x, 才知道由什么组成的, 所以需要从后往前, 直到为0位置, 不算上0
    {
        res += tr[i];
    }
    return res;
}

int main()
{
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i ++) cin >> a[i];//  差分数组用到a[0] = 0, 所以从1开始

    // 先建树

    for(int i = 1 ; i <= n ; i ++)
    {
        add(i, a[i] - a[i-1]);
    }

    for(int i = 0 ; i < m ; i ++)
    {
        char op[2];
        cin >> op;
        if(op[0] == 'Q')
        {
            int x;cin >> x;
            cout << sum(x) << endl;// 差分数组要求一个点的值就是求和
        }
        else 
        {
            int l, r, d;
            cin >> l >> r >> d;
            add(l, d), add(r + 1, -d);
        }
    }


    return 0;
}