#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

typedef pair<int, int> pii;

const int N = 200010;

vector<int> a[2 * N];// 边

void solve()
{       
    int n, m; cin >> n >> m;
    for(int i = 0 ; i < m ; i ++)
    {
        int t, x, y; cin >> t >> x >> y;
        a[x].push_back(y);
    }
}

signed main()
{
    int _ ; cin >> _;
    while(_--) solve();
    return 0;
}

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
