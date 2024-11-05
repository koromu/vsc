#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int a[N], b[N];
int n;

void solve()
{
    int x, y ,k; cin >> x >> y >> k;
    
    if(k == 1)
    {
        cout << x << " " << y << "\n";
        return ;
    }
    x *= k, y *= k;
    if(k % 2 == 0)
        {
            for(int i = 1 ; i <= k / 2 ; i ++)
            {
                // k个x
                a[i] = x - i;
                b[i] = y - i;
            }
            for(int i = 1, j = k / 2 + 1; i <= k / 2 ; i ++)
            {
                a[j] = x + i;
                b[j] = y + i;
            }    
        }
    else
    {
        for(int i = - (k / 2), j = 1; j <= k ; i ++, j ++)
        {
            a[j] = x + i;
            b[j] = y + i;
        }
    }
    int sumx = 0, sumy = 0;
    for(int i = 1 ; i <= k ; i ++)
    {
        cout << a[i] << " " << b[i] << "\n";
        sumx += a[i], sumy += b[i];
    }
    cout << "ans ： " <<  sumx / k << " " << sumy / k << "\n";

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