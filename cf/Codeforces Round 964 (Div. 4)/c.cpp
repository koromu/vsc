#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int n, s, m; cin >> n >> s >> m;
    vector<pair<int, int>> v1;
    for(int i = 1 ; i <= n ; i ++)
    {
        int x, y; cin >> x >> y;
        v1.push_back({x, y});
    }
    sort(v1.begin(), v1.end());
    int ans = max(0, v1[0].first - 0);
    // for(int i = 0 ; i < n ; i ++) cout << v1[i].first << " " << v1[i].second << "\n";
    for(int i = 0 ; i + 1 < n ; i ++)
    {
        // 根据左端点排序
        auto xx = v1[i], yy = v1[i + 1];
        // cout << yy.first << " " << xx.second << "\n";
        ans = max(ans, yy.first - xx.second);
    }

    ans = max(ans, m - v1.back().second);

    // cout << "s : " << s << " " << ans << "\n";

    if(ans < s) cout << "NO\n";
    else cout << "YES\n";


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