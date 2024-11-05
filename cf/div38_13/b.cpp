#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;
bool st[N];

void solve()
{
    cin >> n;
    for(int i = 0 ; i <= n ; i ++) st[i] = false;

    for(int i = 1 ; i <= n ; i ++) cin >> w[i];
    st[0] = st[n + 1] = 0;

    for(int i = 1 ; i <= n ; i ++)
    {
        if(i == 1)
        {
            st[w[i]] = true;
        }
        else
        {
            // cout << w[i] - 1 << " " << w[i] + 1 << " " << st[w[i] - 1] << " " << st[w[i] + 1] << "\n";
            if(st[w[i] - 1] == 0 || st[w[i] + 1] == 0)
            {
                st[w[i]] = true;
                // return;
            }
            else{
                cout << "NO\n";
                return;
            }
        }
        // for(int j = 0 ; j <= 10 ; j ++) 
        // {
        //     cout << st[j] << " ";
        // }
        // cout << "\n";
    }
    cout << "YES\n";
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