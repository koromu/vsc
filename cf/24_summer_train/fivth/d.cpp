#include <iostream>
#include <queue>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 +10, M = 0;
int w[N];
void solve()
{
    vector<pii> v1;
    priority_queue<pii> q;
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        int tmp; cin >> tmp;
        if(tmp)
            q.push({tmp, i});
    }

    while(q.size() >= 2)
    {
        pii x = q.top(); q.pop();
        pii y = q.top(); q.pop();
        v1.push_back({x.second, y.second});
        x.first--, y.first--;
        if(x.first > 0) q.push(x);
        if(y.first > 0) q.push(y);
    }
    cout << v1.size() << endl;
    for(auto i : v1) cout << i.first << ' ' << i.second << endl;
}
signed main()
{
    int t = 1;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
