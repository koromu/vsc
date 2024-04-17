#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2000010; // 是个环, 开双倍

int o[N], d[N];

int q[N];
ll s[N];
bool st[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &o[i], &d[i]);
    // 顺时针做
    for (int i = 1; i <= n; i++)
    {
        // 先计算变化量
        s[i] = s[i + n] = o[i] - d[i];
    }
    // for(int i = 2 * n ; i >= 1 ; i --) cout << s[i] << " ";
    // cout << "\n" ;

    for (int i = 1; i <= 2 * n; i++)
        s[i] += s[i - 1];

    // for(int i = 2 * n ; i >= 1 ; i --) cout << s[i] << " ";
    // cout << "\n" ;

    int hh = 0, tt = -1;
    for (int i = 2 * n; i >= 1; i--) // 顺时针从
    {                                // 这里的q[hh] 是 在i的右边的, 所以要期间从i开始 长度等于n, 条件就是 q[hh] - i + 1 >= n + 1的全部踢出去
        if (hh <= tt && q[hh] - i >= n )
            hh++; // 我们要维护n - 1个元素, 所以看区间长度大于等于n, 就把队头弹出去
        while (hh <= tt && s[q[tt]] >= s[i])
            tt--;
        q[++tt] = i;
        if (i <= n && s[q[hh]] - s[i - 1] >= 0)
            st[i] = true; // 注意是求包括i这个点的, 所以减 i - 1
        // 因为是顺时针, 枚举起点, 所以用在右边区间内的一个前缀和减去这个起点的值, 要这个最小, 所以这个区间的一个前缀和是最小值
    }
    s[2 * n + 1] = 0;
    // 这时候还要有一个后缀和
    d[0] = d[n];
    for (int i = n; i >= 1; i--)
        s[i] = s[i + n] = o[i] - d[i - 1];//这里是用后面的油量减去前面的耗油量, 所以会出现o[1] - d[0], 其中d[0] 就是1 -> n的耗油量, 就是dn

    for (int i = 2 * n; i >= 1; i--)
        s[i] += s[i + 1]; // s[i - 1] += s[i], 然后从2 * n 开始


    hh = 0, tt = -1;
    // 逆时针的话, 那就是从右往左, 然后看的就是右端点的合法性, 然后右端点从左边开始枚举
    for (int i = 1; i <= 2 * n; i++)
    {
        if (hh <= tt && i - q[hh] >= n )//?
            hh++; // 这里也要插入第i个元素
        // 然后计算这个左边区间的最小值减去这个i的值, 判断是不是要更新更新
        while (hh <= tt && s[q[tt]] >= s[i]) 
            tt--; // 维护一个队头元素最下的区间, 也就是递增区间
        q[++tt] = i;
        if (i > n && s[q[hh]] - s[i + 1] >= 0)//注意这个下标, q[hh]是左区间的一个后缀和的下标, i是右边的, 要用的是 q[hh] ~ i的区间合, 所以要减去i右边的一个, 也就是i + 1
            st[i - n] = true;
    }
    

    for (int i = 1; i <= n; i++)
        if (st[i])
            puts("TAK");
        else
            puts("NIE");

    return 0;
}