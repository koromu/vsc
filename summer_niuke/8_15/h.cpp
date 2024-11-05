#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 998244353; 
const int N = 200010;
int w[N];
int n;

int qmi(int a, int b, int p)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = ((res * a) % p);
        a = ((a * a) % p);
        b >>= 1;
    }
    return res;
}

void solve()
{
    int x, y; cin >> x >> y;
    
    // 求出x + y的逆元
    // cout << x + y << "\n";
    int inv = qmi(x + y, P - 2, P);
    // cout << inv << "\n";
    cout << ((x * inv) % P) << ' ' << ((y * inv) % P) << '\n';

}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}