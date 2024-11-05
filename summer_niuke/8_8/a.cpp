#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
map<int, int> mp;

void solve()
{
    cout << cnt * (cnt - 1) << "\n";
    // for(int i = 1 ; i <= cnt ; i ++) cout << primes[i] << ' ';
    // cout << "\n";
    // int n; cin >> n;
    // mp.clear();
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     cin >> w[i];
    //     mp[w[i]]++;
    // }
    // int ans = 0;
    // for(int i = 1; i <= n ; i ++)
    // {
    //     for(int j = 1 ; j <= n ; j ++)
    //     {
    //         int tmp = __gcd(w[i], w[j]);
    //         if(mp[tmp] == 0)
    //         {
    //             cout << "tmp : " << tmp << "\n";
    //             mp[tmp]++;
    //             w[++n] = tmp;
    //             ans ++;
    //         }
    //     }
    // }
    // cout << "n : " << n << "\n";
    // cout << ans << "\n";
    // if(ans % 2 == 1) cout << "d\n";
    // else cout << "h\n";
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    get_primes(N);
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}