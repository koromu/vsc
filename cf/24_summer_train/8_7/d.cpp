#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int P = 1e9 + 7; 
const int N = 200010;
int n;

// 写一个cmp重构优先队列的比较函数
class cmp
{
public:
    bool operator()(pair<int, pii> a, pair<int, pii> b)
    {
        if(a.first == b.first)
        {
            return a.second.first >= b.second.first;
        }
        return a.first < b.first;
    }
};


// bool cmp(pair<int, pii> a, pair<int, pii> b)
// {
//     if(a.first == b.first)
//     {
//         return a.second.first < b.second.first;
//     }
//     return a.first > b.first;
// }

void solve()
{

    int n; cin >> n;// 可能是奇数和偶数
    int op = 1;
    int w[N] = {0};
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, cmp> q;
    q.push({n, {1, n}});
    // w[(1 + n) / 2] = op++;
    
    while(q.size())
    {
        auto [x, p] = q.top();
        q.pop();
        int mid = p.first + p.second >> 1;
        // cout << "mid :" << mid << endl;
        w[mid] = op++;
        if(p.first < mid)
        {
            q.push({mid - p.first, {p.first, mid - 1}});
            // cout << "长度:  "<< mid - p.first << endl;
        }
        if(p.second > mid)
        {
            q.push({p.second - mid, {mid + 1, p.second}});// 如果不相等, 也就是mid不是一个端点
            // cout << "长度:  "<< p.second - mid << endl;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << w[i] << " ";

    cout << endl;

}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}