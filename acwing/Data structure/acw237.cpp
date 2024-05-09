#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

const int N = 200010;

unordered_map<int, int> ha;

struct Q{
    int x, y, e;
}Qs[N];

int idx = 0;
int p[N];
int get(int x)
{
    if(ha.count(x) == 0) ha[x] = ++idx;
    return ha[x];// 如果已经存在了, 直接返回之前的坐标
}// 这就是个离散化的过程, idx就是这个离散化后的数字的相对大小的位置
// 如果存在的话相对位置是相同的, 而且也可以发现, 相对位置的数字只是个编号, 而不是顺序

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}// 常见的路劲压缩的模板

void solve()
{
    // 一个好的处理, 先把所有的输入读进来, 然后先把一个相等的关系数组处理好来, 然后再判断不相等的情况, 一遇到不对的就直接停止
    // 如果是边读入边边建立集合的话, 那么有什么区别呢? 可以试一下
    // 首先需要一个并查集的p数组
    // 然后需要一个
    // 一个经典的离散化方法, 就是排序, 去重
    // 这里的话, 我们选择使用一个unordered_map进行离散化, 第二个元素可以存编号, 第一个元素就是存数值, 这样的话就可以自动排序, 也就是映射一下

    // 询问有三个数据, 所以需要用一个可以存三个值得东西存, 而且询问里面存的应该是x1 x2 e, 所以首先用的是结构体来存
    // 其次应该存什么呢, x1 x2的范围是1e9, 我们首先进行离散化, 因为这两个值是要用来查询p数组的
    ha.clear();
    int n;
    idx = 0;
    cin >> n;
    int a, b, c;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a >> b >> c;
        Qs[i] = {get(a), get(b), c};// c是一个操作, 用get得到离散化后的操作
    }

    for(int i = 1 ; i <= idx ; i ++) p[i] = i;// 这个不是用到n, 而是用用到idx, 如果不放心那就用到N
    // 得到了离散化后的一个Qs数组
    for(int i = 0 ; i < n ; i ++)
    {
        int pa = find(Qs[i].x), pb = find(Qs[i].y);
        if(Qs[i].e == 1)// 把不等集合找到
        {
            p[pa] = pb;// 合并一下
        }
        else 
        {
            if(pa == pb)
            {
                puts("NO");
                return ;
            }
        }
    }

    // for(int i = 0 ; i < n ; i ++)
    // {
    //     if(Qs[i].e == 0)
    //     {
    //         int pa = find(Qs[i].x), pb = find(Qs[i].y);
    //         if(pa == pb)
    //         {
    //             puts("NO");
    //             return ;
    //         }
    //     }
    // }

    puts("YES");
}

int main()
{
    //首先有测试用例个数
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}