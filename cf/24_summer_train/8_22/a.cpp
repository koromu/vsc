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
    int n, k, x; cin >> n >> k >> x;
    vector<int> v1;

    map<int, int> mp;
    for(int i = 1 ; i <= k ; i ++)
    {
        if(n % i != x)
        {
            cout << "YES\n";
            if(n % i != 0){
                cout << n / i + 1 << "\n";
                cout << n % i << " ";
            }
            else 
            {
                cout << n / i << "\n";
            }
            while(n)
            {
                cout << i << " ";
                n -= i;
            }
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
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