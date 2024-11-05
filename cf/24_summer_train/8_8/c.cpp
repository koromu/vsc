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
    map<int, int> mp;
    int n; cin >> n;
    int maxs = 0, maxv = 0;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> w[i];
        mp[w[i]] ++;
        
        if(mp[w[i]] > maxs)
        {
            maxs = mp[w[i]];
            maxv = w[i];
        }
        // maxs = max(maxs, mp[w[i]]);
    }
    if(maxs == 1 && n >= 2)
    {
        cout << "1\n";
        return;
    }
    map<int, int> ha;
    int dif = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(ha[w[i]] == 0)// 不存在这个数, 存在的就不加, 被应用的也不加
        {
            ha[w[i]]++;
            dif ++;
        }
    }

    // 这是包含第二个组的组数
    // 得到了元素最多的那个元素

    if(dif - 1 >= maxs) cout << maxs << "\n";
    else cout << min(dif, maxs - 1) << "\n";


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