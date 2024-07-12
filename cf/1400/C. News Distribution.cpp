#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 500010;
int p[N * 2 + 5], w[N  * 2 + 5];// 并查集

int n, m;
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void init()
{
    for(int i = 1 ; i <= n + m ; i ++)
        p[i] = i;
    for(int i = 1 ; i <= n ; i ++) w[i] = 1;
}

signed main()
{
    cin >> n >> m;
    init();
    for(int i = 1 ; i <= m ; i ++)
    {
        int k; cin >> k;
        for(int j = 0 ; j < k ; j ++)
        {// 当前这个人是一个集合n + i，然后还有另一个集合就是
            int mes; cin >> mes;// 读入一个这个人能联系到的人
            int fa = find(mes);// 取出这个节点的父节点，可能是自己，也可能是别人
            // 然后把这些人都加到一个集合中
            // 如果这个mes的父节点不是自己的话，那可以进来，以防止重复加两个父节点都是自己的节点，这就是路径压缩的好处呀
            if(fa != find(n + i))
            {
                w[n + i] += w[fa];
            }
            p[fa] = find(n + i);// 把这个mes的父节点变化成当前节点
        
        }// 最后大于的是当前节点的父节点的数量，那么就把这个这个mes的父节点的值加给当前节点
    }
    // for(int i = 1 ; i <= n + m; i ++) cout << p[i] << " ";
    // cout << endl; // 分组正确

    // 然后
    for(int i = 1 ; i <= n ; i ++)
    {
        cout << w[find(i)] << " ";
    }
    return 0;
}
