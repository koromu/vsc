#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define PII pair<int, int>
// #define l first
// #define r second
const int N = 1e6 + 10, M = 0;
string mp[2];

int lowbit(int x) {return x & -x;}

void solve()
{
    int n; cin >> n;
    if(n != 1)
        if(n % 2 == 0) 
            if(n - lowbit(n) == 0) puts("-1");
            else cout << n - lowbit(n) << endl;
        else cout << 1 << endl;
    else cout << -1 << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
       cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
