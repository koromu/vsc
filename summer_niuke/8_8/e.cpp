#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;
vector<int> v1[N];

void solve()
{
    int n; cin >> n;
    map<int, int> mp;
    for(int m = 1 ; m <= n ; m ++)
    {
        cout << "n : " << n << " 余数 : " << n % m << " m: " << m << "\n";
        mp[n % m] ++;
    }
    // for(auto x : mp) cout << x .first << " ";
    cout << "\n"; 
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