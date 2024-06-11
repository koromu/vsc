#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 40010, M = 2 * N;

int h[N], e[M], ne[M], idx;
int death[N];//每个点距离根节点的距离
int fa[N][16];//第一个参数是节点的参数, 第二个参数是最多跳过的祖宗节点
int q[N];

int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs(int root)
{
    death[root] = 1;
    queue<int> q;
    // 枚举所有点, 初始化所有的深度数组, 还有fa数组
    q.push(root);
    
    
}



int lca(int a, int b)
{
    if(death[a] > death[b])
    swap(a , b);//这样的话b的深度总是更深的那个
    //先跳到同一个深度
    for(int i = 15 ; i >= 0 ; i --)
    {
        if(death[a] < death[fa[b][i]])//如果跳了以后, 还是在a的下面, 直接更新
            b = fa[b][i];
    }
    //跳完之后, 如果还是
    
    //最后出来的时候, 肯定是在同一层了
    for(int i = 15 ; i >= 0 ; i --)//然后一起跳
    {
        if(fa[a][i]!= fa[b][i])
        {
            //如果祖宗不相同, 那么就更新
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    //最后出来的时候就是公共的祖先的下一层
    if(fa[a][0] == b) return 2;
    else if (fa[b][0] == a) return 1;
    else return 0;
}

int main()
{
    
    cin >> n;
    int root;
    memset(h , -1, sizeof h);
    for(int i = 0 ; i < n ; i ++)
    {
        int a, b;
        cin >> a >> b;
        if(!a) add(a, b), root = b;
        else if(!b) add(b, a), root = a;
        else add(a, b), add(b, a);
    }
    memset(death, 0x3f, sizeof death);
    
    bfs(root);
    cin >> m;
    for(int i = 0 ; i < m ; i ++)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    
    return 0;
}