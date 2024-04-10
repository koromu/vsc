#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

//如果有一个点没有被更新, 那么就是无法送达的站点, 所以最后遍历一下每个点的最短距离
//还是一样, 从一个点出发, 一个图是可以全部到达的, 那么最短时间, 就是所有距离中的最大距离
using namespace std;

const int N = 110, M = 410;

typedef pair<int, int> pii;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int n, m;
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    pq.push(make_pair(dist[1], 1));
    while(pq.size())
    {
        int val = pq.top().first;
        int id = pq.top().second;
        pq.pop();
        if(st[id]) continue;//如果已经出过队了, 可能就是在后背更新了比先前加入的点更短的点, 所以这个点是过时的点
        st[id] = true;  
        for(int i = h[id] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            if(!st[j])
            {
                if(dist[j] > val + w[i])
                {
                    dist[j] = val + w[i];
                    pq.push(make_pair(dist[j], j));
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0 ; i < m ; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dijkstra();
    int ans = 0;
    for(int i = 1 ; i <= n; i ++) 
    {
        if(dist[i] == 0x3f3f3f3f)
        {
            puts("-1"); 
            return 0;
        }
        else ans = max(ans, dist[i]);
    }
    
    cout << ans << endl;
    return 0;
}