#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

int lcm(int a,int b)
{
    return a / __gcd(a,b) * b;
}

void solve()
{
    int n; cin >> n;
    // for(int i = 1 ; i < sqrt(n) ; i ++)
    // {
    //     for(int j = 1 ; j < sqrt(n) ; j ++)
    //     {
    //         for(int k = 1 ; k < n ; k ++)
    //         {
    //             if(lcm(i,j) == __gcd(n - i - k - j,k))
    //             {
    //                 cout << i << ' ' << j << ' ' << k << " " << n - i - j - k << '\n';
    //                 return;
    //             }
    //         }
    //     }
    // }
    cout << 1 << " " << n - 3 << " " << 1 << " " << 1 << "\n";
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