// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// #define int long long
// using namespace std;

// typedef pair<int, int> pii;

// const int N = 200010;

// vector<int> a[2 * N];// 边

// void solve()
// {       
//     int n, m; cin >> n >> m;
//     for(int i = 0 ; i < m ; i ++)
//     {
//         int t, x, y; cin >> t >> x >> y;
//         a[x].push_back(y);
//     }
// }

// signed main()
// {
//     int _ ; cin >> _;
//     while(_--) solve();
//     return 0;
// }

// 一个有向无环图一定有一个入度为0的点


// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <tuple>

// using namespace std;

// bool topologicalSort(int n, vector<vector<int>>& adj, vector<int>& order) {
//     vector<int> indegree(n, 0);
//     for (int i = 0; i < n; ++i) {
//         for (int v : adj[i]) {
//             indegree[v]++;
//         }
//     }

//     queue<int> q;
//     for (int i = 0; i < n; ++i) {
//         if (indegree[i] == 0) {
//             q.push(i);
//         }
//     }

//     int count = 0;
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         order.push_back(u);
//         count++;

//         for (int v : adj[u]) {
//             if (--indegree[v] == 0) {
//                 q.push(v);
//             }
//         }
//     }

//     return count == n;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n, m;
//         cin >> n >> m;

//         vector<pair<int, int>> undirected;
//         vector<vector<int>> adj(n);
//         vector<tuple<int, int, int>> edges(m);

//         for (int i = 0; i < m; ++i) {
//             int t, u, v;
//             cin >> t >> u >> v;
//             u--; v--;
//             edges[i] = {t, u, v};
//             if (t == 1) {
//                 adj[u].push_back(v);
//             } else {
//                 undirected.push_back({u, v});
//             }
//         }

//         vector<int> order;
//         if (!topologicalSort(n, adj, order)) {
//             cout << "NO" << endl;
//             continue;
//         }

//         unordered_map<int, int> position;
//         for (int i = 0; i < n; ++i) {
//             position[order[i]] = i;
//         }

//         bool possible = true;
//         for (auto& edge : undirected) {
//             int u = edge.first, v = edge.second;
//             if (position[u] < position[v]) {
//                 adj[u].push_back(v);
//             } else {
//                 adj[v].push_back(u);
//             }
//         }

//         order.clear();
//         if (!topologicalSort(n, adj, order)) {
//             possible = false;
//         }

//         if (possible) {
//             cout << "YES" << endl;
//             for (auto& edge : edges) {
//                 int t, u, v;
//                 tie(t, u, v) = edge;
//                 if (t == 1 || position[u] < position[v]) {
//                     cout << u + 1 << " " << v + 1 << endl;
//                 } else {
//                     cout << v + 1 << " " << u + 1 << endl;
//                 }
//             }
//         } else {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#define int long long
using namespace std;

typedef pair<int, int> pii;

const int N = 200010;

vector<int> h[N];// 存边
vector<pii> h2;// 存要处理的边
int dis[N];// 存一个点的入度
int q[N];
int n, m; 

bool topsort()
{
    // 先把所有入度为0的点加到队列里面
    int hh = 0, tt = -1;// 拓扑排序手写有奇效 
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(dis[i] == 0)
        {
            q[++tt] = i;// 这个点加到队列中
        }
    }
    int count = 0;
    while(hh <= tt)
    {
        
        int point = q[hh++];// 取出队头元素
        for(int i = 0 ; i < h[point].size() ; i ++)
        {
            int j = h[point][i];// 得到指向的边
            count ++;
            // 遍历所有子节点
            dis[j]--;
            if(dis[j] == 0)
            {
                // 可以加到队列中了
                q[++tt] = j;
            }
        }
    }
    // if(n == 1000)
        // cout << count << " " << hh << endl;
    return hh == n;// 如果出队的点的个数刚好是n的话，说明是拓扑图，否则就是有环
}

void init()
{
    h2.clear();
    for(int i = 1 ; i <= n ; i ++)
        h[i].clear();
    memset(dis, 0, sizeof dis);
}

void solve()
{
    init();
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++)
    {
        int t, x, y;// 把这个存起来
        cin >> t >> x >> y;
        // edges.push_back({t, x, y}); // 存起来已准备给后面的判断完之后用
        if(t == 1)
        {
            h[x].push_back(y);
            dis[y]++;
        }
        h2.push_back({x,y});
    }
    // for(int i = 0 ; i < n ; i ++) cout << dis[i] << " ";
    // cout << endl; 
    if(topsort())
    {
        puts("YES");
        // 如果这个图是拓扑图，那么就可以进行下一步了
        // h2进行处理, 已知拓扑排序, 然后可以我们要连完这些边之后也是拓扑的
        // 所以我们要用拓扑序靠前的连向靠后的
        // 先打印h数组中的图
        
        // 对于不需要处理的边只要直接输出就行了
        // 需要处理的边的话就需要看拓扑排序的结果了
        // 然后为了直接可以得到两个点的拓扑排序，需要一个哈希表直接索引
        unordered_map <int ,int> ha;
        for(int i = 0 ; i < n ; i ++)
        {
            // 遍历一遍拓扑排序
            ha[q[i]] = i; // 前面的拓扑序对于的数值
        }
        // for(int i = 0; i < n ; i ++) cout << q[i] << " ";
        // cout << endl;
        // cout << endl;
        // for(auto i : ha) cout << i.first << " " << i.second << " " << endl;
        // cout << endl;
        // cout << endl;
        for(auto i : h2)
        {
            // 遍历每一个边
            if(ha[i.first] < ha[i.second]) cout << i.first << " " << i.second << endl;
            else cout << i.second << " " << i.first << endl;
        }
    }
    else puts("NO");
}

signed main()
{   
    int _; cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}