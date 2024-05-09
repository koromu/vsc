#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// typedef pair<int , int> pii;
// vector<pii> v1;//读入一个v 和 w的话就合并这两个的集合, 包括体积和价值
const int N = 10010;
int W[N], V[N], p[N];
int f[N];// 做一个01背包问题, 从前i个中选, 总体积不超过j的最大值
int find(int x)
{// 这里需要知道一个问题, 就是合并的过程中体积和价格也要合并, 但是在哪合并呢, 好像不是这里
    if(x != p[x]) p[x] = find(p[x]);//找到了根节
    return p[x];
}

int main()
{
    // 首先买一个一定要另一个, 所以有一个传递性
    // 并且这个不像有依赖的背包问题
    // 不能只考虑一个, 需要考虑一个整体, 所以可以对一个整体计算一次
    // 所以可以先把一堆物品合成一个物品, 然后因为存在价值和价格, 所以需要把合并以后的价格和价值也合起来
    // 所以是一个W数组, 一个V数组

    // 然后给我们一个总体积(价格的最大容量)w, 让我们求出一个最大价值
    // 一个p数组, 记录的是每个物品的祖宗关系, 也就是并查集的集合关系
    // 所有的加在哪呢, 显然加到根节点上, 根节点就是x = p[x]的节点
    int n, m, w;
    std::cin >> n >> m >> w;
    for(int i = 1; i <= n ; i ++) std::cin >> V[i] >> W[i];

    for(int i = 1 ; i <= n ; i ++) 
        p[i] = i;
    
    for(int i = 0 ; i < m ; i ++)
    {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if(pa != pb){
            p[pa] = pb;//pa指向了pb
            W[pb] += W[pa];
            V[pb] += V[pa];// 这就算合并成功了? 错误的! 一个物品可能还没有被其他的连起来
        }
    }

    //遍历所有物品, 
    for(int i = 1 ; i <= n ; i ++)
    {   
        if(p[i] == i)// 如果是根节点的话, 就算, 不是就不算
        {
        for(int j = w; j >= V[i] ; j --)
            f[j] = max(f[j], f[j - V[i]] + W[i]);// 经典的等价变形
        }
    }

    cout << f[w] << endl;
    return 0;
}