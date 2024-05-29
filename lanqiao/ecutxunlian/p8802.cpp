#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <math.h>
#include <queue>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 10010, M = 1010;;
int w1[M];// 存要隔离的时间
int w2[M][M];
vector<int> e1[2 * N];

int n, m;

int s[M];// 记录最短距离
bool st[M];
signed main()	
{
    cin >> n >> m;
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    memset(s, 0x3f, sizeof s);
    for(int i = 1; i <= n ; i ++) cin >> w1[i];
    for(int j = 1; j <= m; j ++) 
    {
        int u, v, w; cin >> u >> v >> w;
        e1[u].push_back(v);
        e1[v].push_back(u);
        w2[u][v] = w2[v][u] = w;
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    s[1] = 0;
    int tt = 0;

    while(!q.empty())
    {
        int t = q.top().second;
        q.pop();
        if(st[t]) continue;// 出过队就不用再出了
        st[t] = true;
        // cout << t << endl;
        for(auto v : e1[t])
        {
            // cout << v << endl;
            if(!st[v])
            {
                // 遍历这个节点的所有子节点
                if(s[t] + w1[v] + w2[t][v] < s[v])
                {
                    s[v] = s[t] + w1[v] + w2[t][v];// 从当前点去别的点的时间, 加上别的点的隔离时间
                    q.push({s[v], v});
                }
            }
        }
        // cout << "s[t] : " << s[t] << endl;
        // cout << endl;
    }
    cout << s[n] - w1[n] << endl;

    return 0;
}