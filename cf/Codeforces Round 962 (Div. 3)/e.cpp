#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
const int P = 1000000007;
int pre[N];
vector<int> v1[N * 2];

void solve() {
    string a; cin >> a;
    a = ' ' + a;
    for(int i = 1; i <= a.size() - 1 + N ; i ++) v1[i].clear();
    for(int i = 1 ; i <= a.size() - 1 ; i ++)
    {
        pre[i] = pre[i - 1] + (a[i] == '1' ? 1 : -1);// 前缀和为0的时候才算出来
        // std::cout << pre[i] << " ";
    }
    // std::cout << "\n";
    for(int i = 0 ; i <= a.size() - 1 ; i ++)
    {
        v1[pre[i] + N].push_back(i);
    }
    int ans = 0;


    map<int, int> sum;
    int n = a.size() - 1;

    for(int i = n ; i >= 0 ; i --)// 遍历前缀和数组
    {
        if(v1[pre[i] + N].size() >= 2)// 至少有一队的话
        {
            ans = (ans + (i + 1) * sum[pre[i]] % P ) % P;
            // std::cout << pre[i] << " " << sum[pre[i]] << "\n";
        }
        sum[pre[i]] = (sum[pre[i]] + (n - i + 1) ) % P;
    }

    std::cout << ans << endl;
    
    
    // for(auto vv : v1)
    // {
        // if(vv.size() >= 2)
        // {
            // std::cout << vv.size() << "\n";
            // for(int i = vv.size() - 1 ; i >= 1 ; i --)
            // {
                // for(int j = i + 1 ; j <= vv.size() - 1; j ++ )
                // {
                //     // std::cout << vv[i] << " " << vv[j] << endl;
                //     // std::cout << a.size() - 1 << "\n";
                //     ans = (ans + (((vv[i] + 1) % P) * (a.size() - vv[j])) % P )% P;
                // }
            // }
        // }
    // }
    // std::cout << ans << endl;



}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
