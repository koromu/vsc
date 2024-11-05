#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
// int n;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if(n >= k && m >= k)
    {
        cout << k * k << "\n";
    }
    else if(n >= k && m < k)
    {
        cout << m * k << "\n";
    }
    else if(m >= k && n < k)
    {
        cout << n * k << "\n";
    }
    else if(n < k && m < k)
    {
        cout << n * m << "\n";
    }

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