#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 200010;

vector<int> h[N];
ll w[N]; // 存的是这个点的叶子结点
// set<pii> s;
int n;

ll dfs(int u)
{
    //如果不为空遍历子树
    if (h[u].size()) // 返回的是子节点的个数
    {
        for (auto v : h[u]) // 遍历子节点
        {
            w[u] += dfs(v);
        }
    }
    else//否则直接返回1
        w[u] = 1;
    // w[u] = cnt;
    // return cnt;
    return w[u];
}

void dfs(int u, int fa)
{
    if(h[u].size() == 1 && h[u][0] == fa)//如果只有一个, 而且是指向父节点的
    {
        w[u] = 1;
        return ;
    }
    else if(h[u].size())
    {
        //不为空是进去
        for(auto v : h[u])
        {
            if(v != fa)
            {
                dfs(v, u);
                w[u] += w[v];
            }//如果不是指到父节点了
        }
    }
    //如果是空的说明这个就是, 不可能是空的

}


void solve()
{
    cin >> n;               // n条边
    memset(w, 0, sizeof w); // 初始化一下
    int a, b;
    memset(h, 0, sizeof h);
    // s.erase(s.begin(), s.end());//清空集合
    for (int i = 0; i < n - 1; i++)
    { // 把所有边存下来, first存父亲, second存儿子
        cin >> a >> b;
        h[a].push_back(b);
        h[b].push_back(a); // first存小的编号
    }
    // 存好了图
    dfs(1, -1); // 从根节点1开始
    int q;
    cin >> q;
    int x, y;
    while (q--)
    {
        cin >> x >> y;
        cout << w[x] * w[y] << endl;
    }
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
}
