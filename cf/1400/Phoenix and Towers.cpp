// #include <bits/stdc++.h>
// using i64 = long long;
// using namespace std;

// typedef pair<int, int> pii;
// const int P = 1e9 + 7; 
// const int N = 1e5 + 10;

// pii heap[N];
// pii w[N];
// int tmple[N];
// bool cmp(pii a, pii b)
// {
//     return a.first < b.first;
// }

// void solve()
// {
//     int n, m, x;
//     cin >> n >> m >> x;
//     for(int i = 0 ; i <= n ; i ++) heap[i].first = heap[i].second = 0;
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         cin >> w[i].first;
//         w[i].second = i;// 存了一个原下标
//     }

//     sort(w + 1, w + n + 1);// 先放m个最大的
//     // for(int i = 1; i <= n ; i ++) cout << w[i].second << " " << w[i].first << "\n";

//     int hh = 0, tt = -1;
//     for(int i = n ; i >= n - m + 1 ; i --)
//     {
//         heap[++tt].first = w[i].first;
//         heap[tt].second = tt + 1;// 存好下标
//         tmple[i] = heap[tt].second;
//     }
//     //
//     for(int i = n - m ; i >= 1 ; i --)
//     {
//         sort(heap, heap + tt + 1, cmp);
//         // 取出最小的那个, 然后加上这个w[i], 然后把这个下标给tmple[i]
//         tmple[i] = heap[0].second;
//         heap[0].first += w[i].first;// 直接改就是了, 然后排序
//         // for(int k = 0 ; k <= tt ; k ++) cout << heap[k].first << " ";
//         // cout << "\n";
//     }

//     sort(heap, heap + tt + 1, cmp);

//     bool flag = true;
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         if(heap[tt].first - heap[0].first > x)
//         {
//             flag = false;
//             break;
//         }
//     }
//     int ans [N];
//     if(flag)
//     {
//         cout << "YES\n";
//         for(int i = 1; i <= n ; i ++ )
//         {
//             ans[w[i].second] = tmple[i];
//         }
//         for(int i = 1 ; i <= n ; i ++)
//         {
//             cout << ans[i] << " ";
//         }
//         cout << "\n";
//     }
//     else cout << "NO\n";

// }


// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     cin >> t;
//     while(t--)
//         solve();

// return 0;
// }
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

typedef pair<int, int> pii;
const int P = 1e9 + 7; 
const int N = 1e5 + 10;

pii w[N];
int tmple[N];

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> heap(m + 1, 0); // 用于记录每个塔的高度
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 最小堆，用于维护当前塔的高度和对应的索引

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i].first;
        w[i].second = i; // 存储原始下标
    }

    sort(w + 1, w + n + 1, greater<pii>()); // 按照高度从大到小排序

    for (int i = 1; i <= m; ++i)
    {
        pq.push({0, i}); // 初始化每个塔的高度为0，并存入堆中
    }

    for (int i = 1; i <= n; ++i)
    {
        auto [height, idx] = pq.top(); pq.pop();
        tmple[w[i].second] = idx;// 在原始坐标上存一个idx, idx的范围是1 ~ m
        height += w[i].first;
        pq.push({height, idx});
    }

    auto [minv, _] = pq.top(); pq.pop();
    while (!pq.empty())
    {
        auto [height, _] = pq.top(); pq.pop();
        if (height - minv > x)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << tmple[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
