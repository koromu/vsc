#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int n; cin >> n;
    int w[N];
    int cj = 0 ,co = 0;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> w[i];
        if(w[i] % 2 == 0) co++;
        else cj++;
    }
    sort(w + 1, w + n + 1);
    // cout << cj << " " << co << "\n";
    if(cj % 2 == 0 && co % 2 == 0)
    {
        cout << "YES\n";
        return;
    }
    if(cj % 2 == 1 && co % 2 == 1){
        for(int i = 1 ; i <= n ; i ++)
        {
            if(w[i] + 1 == w[i + 1])
            {
                cout << "YES\n";
                return;
            }//否则继续算
        }
        cout << "NO\n";
        return;
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