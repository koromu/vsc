#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <math.h>
#include <map>


#define int long long
using namespace std;
const int N = 2e5 + 10;
typedef pair<bool, int> pii;

int w[N];
int pre[N];
map<int, pii> mp;

void solve()
{
    int n; cin >> n;
    pre[0] = 0;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> w[i];
        pre[i] = pre[i - 1] + w[i];
        // cout << pre[i] << " ";
    }
    int ans = 0;
    int l = 0;
    mp[0] = {true,0};
    for(int i = 1; i <= n ; i ++)
    {
        if(mp[pre[i]].first)
        {
            cout << i << "\n";
            int pos = mp[pre[i]].second;
            cout << "l : " << l <<  " pos : " << pos << "\n";
            for(int j = l ; j <= pos ; j++ ){
                mp[pre[j]] = {false, 0};
            }

            // mp[pre[i]] = {true, i};
            // for(auto k : mp) cout << k.first << " " << k.second << "\n"; 

            l = pos;
            ans ++;
        }
        mp[pre[i]] = {true, i};
    }

    // 每一个相同前缀和的数之间都要加上一个数

    cout << ans << "\n";


    return ;
}   


signed main()
{
    int _ = 1; 
    // cin >> _;
    while(_--) solve();
    return 0;
}