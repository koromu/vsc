#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;

void solve()
{
    int n; cin >> n;
    int minv = P, c = 0;
    // for(int i = 1; i <= n ; i ++)
    // {
    //     cin >> w[i];
    //     if(w[i] == minv) c++;
    //     if(w[i] < minv)
    //     {
    //         minv = w[i];
    //         c = 1;
    //     }
    //     // minv = min(minv, w[i]);
    // }
    // cout << "n : " << n << " c : " << c << "\n";
    // cout << n - c << endl;
    map<int, int> mp;
    mp.clear();
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
        mp[w[i]]++;
    }
    int maxv = 0;
    for(auto u : mp)
    {
        // cout << "se : " << u.second << "\n";
        maxv = max(maxv, u.second);
    }
    // cout << n << " " << maxv << "\n";
    cout << n - maxv << "\n";

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