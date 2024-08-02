#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 810, M = 1450;
//每头牛喜欢的地方就是每头牛的在的地方, 现在要找一个牧场, 使得到所有的牧场之和最短
//如果用堆优化的dj, 每次是800 * 12 * 800
typedef pair<int, int> pii; 
// int h[N], e[M], ne[M], w[M], idx;
int w[N][N];
int dist[N];
int cow[N];
bool st[N];
vector<int> edge[M * 2];
int x, n, m, ans = 0x3f3f3f3f;

// void add(int a, int b, int c)
// {
//     e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
// }

int dijkstra(int s)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    priority_queue<pii, vector<pii>, greater<pii>> heap;// 一个小根堆
    dist[s] = 0;
    heap.push({0, s});// 距离和起点的编号
    // cout << heap.top().first << " " << heap.top().second << endl;
    while(heap.size())
    {
        int id = heap.top().second;// 取出当前这个点的编号
        heap.pop();
        if(st[id]) continue;
        st[id] = true;
        for(auto i : edge[id])
        {
            //取出这个点的所有临边
            if(dist[i] > dist[id] + w[id][i])
            {
                dist[i] = dist[id] + w[id][i];
                if(!st[i])
                    heap.push({dist[i], i});
            }
        }
        // for(int i = h[id] ; i != -1 ; i = ne[i])
        // {
        //     int j = e[i];// 取出一个点, 是一个id -> j, i是这个边的编号
        //     if(dist[j] > dist[id] + w[i]);
        //     {
        //         dist[j] = dist[id] + w[i];
        //         if(!st[j])
        //             heap.push({dist[j], j});
        //     }
        // }
    }
    int res = 0;// 做完之后得到了所有牛到这个点的dist的最小值, 然后加起来
    for(int i = 1 ; i <= x ; i ++)//遍历所有的牛
    {
        if(dist[cow[i]] == 0x3f3f3f3f) return 0x3f3f3f3f;
        res += dist[cow[i]];
    }
    return res;
}

int main()
{
    // memset(h, -1, sizeof h);
    cin >> x >> n >> m;
    for(int i = 1 ; i <= x ; i ++) cin >> cow[i];//x头牛, 每头牛所在的位置
    memset(w, 0x3f, sizeof w);
    for(int i = 1 ; i <= x ; i ++) w[i][i] = 0;

    for(int i = 0 ; i < m ; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // add(a, b, c), add(b, a, c);
        edge[a].push_back(b);
        edge[b].push_back(a);
        w[a][b] = w[b][a] = min(w[a][b], c);
    }
    
    for(int i = 1 ; i <= n; i ++) ans = min(ans, dijkstra(i));
    
    cout << ans << endl;
    return 0;
}


// #include <iostream>
// #include <cstring>
// #include <queue>
// #include <vector>
// using namespace std;
// typedef pair <int,int> PII;
// const int N = 810,M = 3010,INF = 0x3f3f3f3f;
// int n,p,m;
// int cow[N];
// int h[N],e[M],w[M],ne[M],idx;
// bool st[N];
// int dist[N];
// void add (int a,int b,int c) {
//     e[idx] = b;
//     w[idx] = c;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }
// int dijkstra (int s) {
//     memset (st,false,sizeof (st));
//     memset (dist,0x3f,sizeof (dist));
//     dist[s] = 0;
//     priority_queue <PII,vector <PII>,greater <PII>> heap;
//     heap.push ({0,s});
//     while (!heap.empty ()) {
//         int id = heap.top ().second;
//         heap.pop ();
//         if (st[id]) continue;
//         st[id] = true;
//         for (int i = h[id];~i;i = ne[i]) {
//             int j = e[i];
//             if (dist[j] > dist[id] + w[i]) {
//                 dist[j] = dist[id] + w[i];
//                 heap.push ({dist[j],j});
//             }
//         }
//     }
//     int ans = 0;
//     for (int i = 1;i <= n;i++) {
//         if (dist[cow[i]] == INF) return INF;
//         ans += dist[cow[i]];
//     }
//     return ans;
// }
// int main () {
//     memset (h,-1,sizeof (h));
//     cin >> n >> p >> m;
//     for (int i = 1;i <= n;i++) cin >> cow[i];
//     while (m--) {
//         int a,b,c;
//         cin >> a >> b >> c;
//         add (a,b,c);
//         add (b,a,c);
//     }
//     int ans = INF;
//     for (int i = 1;i <= p;i++) ans = min (ans,dijkstra (i));
//     cout << ans << endl;
//     return 0;
// }
