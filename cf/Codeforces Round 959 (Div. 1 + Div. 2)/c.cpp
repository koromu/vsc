#include <iostream>

using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 +10, M = 0;
int a[N], b[N];
int w[N];

int dp[N][N];// 当前是第i个, 吃这个蘑菇的方案数的最大值

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        a[i] = a[i-1] + w[i];
    }

    
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
