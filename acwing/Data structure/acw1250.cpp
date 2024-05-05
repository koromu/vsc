#include <iostream>
#include <algorithm>

using namespace std;
const int N = 40010;//每个点有一个集合, 所以是点数n * n 个点
// 首先是一个n, 一个m
// m个输入
int p[N];

// 初始化一个p数组, 就是并查集的数组
// 读入两个点, 然后找到这两个点的根节点, 如果这两个根节点相同, 说明这两个点就是在同一个节点中, 也就是这个在两个原本不相连的点现在连起来了
// 而且在连起来之前这两个点就是连起来的, 也就是这两个点的另一边是连起来的, 也就是比赛结束了
// 那么如果这两个根节点不同, 说明这两个点不在同一个集合中, 说明游戏还没有结束, 需要把这两个点的集合合并起来

// 然后一个find函数
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, m;
    char op[2];
    cin >> n >> m ;
    
    for(int i = 1 ; i <= n * n ; i ++) p[i] = i;
    bool flag = false;
    int i;
    for(i = 1 ; i <= m ; i ++)
    {
        int x, y;
        cin >> x >> y >> op;
        x--, y--;//下标也需要做映射, 从0开始
        // 说明是向下
        int a, b;
        if(op[0] == 'D') 
            a = x * n + y, b = (x + 1) * n + y;//可以发现只需要改变这一步就可以了, 对于向下还是向右
        else a = x * n + y, b = x * n + y + 1;//向右的话就是横坐标加一
        
        int pa = find(a), pb = find(b);//一个常用的将二维的坐标转化成一维的坐标, 就是x * n + y(前提是x和y都是从0开始的, 从1开始的也行, 但是需要修改一下, 感觉不如直接改x和y的值)
        if(pa == pb)
        {
            flag = true;
            break;
        }
        else 
        {
            // 合并一下
            p[pa] = pb;
        }
        
    }
    if(flag) cout << i << endl; 
    else puts("draw");
    return 0;
}