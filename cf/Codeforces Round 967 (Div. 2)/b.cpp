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
    int n; cin >> n;
    if(n % 2 != 0)
    {
        int tmp = 1;
        for(int i = n / 2 + 1; i >= 1 ; i --)
        {
            w[i] = tmp;
            tmp += 2;
        }
        tmp = 2;
        for(int i = n / 2 + 2 ; i <= n ; i ++)
        {
            w[i] = tmp;
            tmp += 2;
        }
        for(int i = 1 ; i <= n ; i ++)
        {
            cout << w[i] << " " ;
        }
        cout << "\n";
    }
    else cout << "-1\n";
    return;
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