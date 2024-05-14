#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 200010;
// 一个就是问有多少个v, 我们可以遍历每一个点, 然后算出来左边有多少个大于这个点的数, 再算出有多少大于这个数的数, 组合起来的话就是左边的乘以右边的
// 另一个是问多少个A形状的, 那么就是遍历每一个点, 算出左右两边小于这两个点的数量, 然后相乘

// 一个原始的数组, a存的是原始数
// 一个记录的是两边有多少个数比当前位置上的数大, 还有一个是记录左右两边有多少个数比当前位置上的数小
// 因为我们现在要求一个总共出现的数中有多少个是大于或者小于这个数
// 所以树状数组中存的就是出现的个数只需要tr[i], 就可以求出1 ~ i中的数的个数, 然后再算出 i + 1 ~ n中的数的个数, 算的时候可以直接乘, 不存到数组中

int a[N];
ll tr[N];
// 树状数组的大小需要大一点
ll Greater[N], Lower[N];
int n;
int lowbit(int x)
{
    return x & -x;
}

void add(int x, int y)
{
    // 在x的位置上加1
    for(int i = x ; i <= n; i += lowbit(i))
        tr[i] += y;
}

ll sum(int x)
{
    ll res = 0;
    for(int i = x ; i ; i -= lowbit(i))
        res += tr[i];// 比小于等于x的数出现的次数
    return res;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];    

    for(int i = 1; i <= n ; i ++)
    {
        Greater[i] = sum(n) - sum(a[i]);// 计算左边有多少个数大于这个数
        Lower[i] = sum(a[i] - 1);// 计算左边有多少个数小于这个数
        add(a[i], 1);// 树状数组中加上这个a[i], 出现次数加1
    }

    memset(tr, 0, sizeof tr);
    ll res1 = 0, res2 = 0;
    for(int i = n ; i >= 1; i --)// 遍历坐标
    {
        res1 += Greater[i] * (sum(n) - sum(a[i]));// 计算的是从a[i] + 1 到n的数中有多少大于a[i]的数
        res2 += Lower[i] * sum(a[i] - 1);// 数组中存的是左边有多少, 所以还需要算一个右边有多少
        add(a[i], 1);
    }
    // 无论比自己低还是比自己高, 都不可以计算自己
    cout << res1 << " " << res2 << endl;
    return 0;
}