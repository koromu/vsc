#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7;
const int N  = 1000010;
int a[N], b[N], c[N];
int dp1[N], dp2[N];

void solve()
{
    int n, m, maxv = 0;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
        maxv = max(maxv, a[i]);
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> b[i];
        dp1[a[i]] = min(dp1[a[i]], a[i] - b[i]);// 直接用dp数组当原数组
    }//dp1[i]原本存的是花费为i的最小差值，这个差值是消耗的铁锭的数量，正数表示消耗，负数是增加，同一个花费我们要消耗越小的
    // 
    for(int i = 1 ; i <= m ; i ++)
    {
        int c; cin >> c;
        ;// 
    }


}


signed main()
{

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}