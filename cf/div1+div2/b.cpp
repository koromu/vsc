#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 300010;
int a[N], b[N];
int n;

void solve()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
    }   
    for(int i = 1 ; i <= n ; i ++) cin >> b[i];
    int hh1 = 1, tt1 = n, hh2 = 1, tt2 = n;
    for(int i = 1 ; i <= n ; i ++)
    {
        if((a[hh1] != b[hh2] && a[hh1] != b[tt2]) || (a[tt1] != b[tt2] && a[tt1] != b[hh2]))
        {
            cout << "Alice\n";
            return;
        }
        if(a[hh1] == b[tt2])
        {
            // 如果有一个相同的话
            hh1++;
            tt2--;
        }
        else if(b[hh2] == a[hh1])
        {
            hh2++;
            hh1++;
        }
        else if(a[tt1] == b[hh2])
        {
            tt1--;
            hh2++;
        }
        else if(b[tt2] == a[tt1])
        {
            tt2--;
            tt1--;
        }

    }
    cout << "Bob\n"; 

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