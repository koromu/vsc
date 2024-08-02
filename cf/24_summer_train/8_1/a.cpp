#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

int a[N], b[N];
map<int, int> mpa, mpb;

void solve()
{
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
        mpa[a[i]]++;
    }   
    int m; cin >> m;
    for(int i = 1 ; i <= m ; i ++)
    {
        cin >> b[i];
        mpb[b[i]]++;
    } 


    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= m ; j ++)
        {
            int c = a[i] + b[j];
            if(mpa[c] == 0 && mpb[c] == 0)
            {
                cout << a[i] << " " << b[j] << "\n";
                return ;
            }
        }
    }
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