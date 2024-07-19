#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int w[N];
int ans[N];
int fa[N];
int q[N * 4];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> w[i];
    int hh = N, tt = N + 1;
    for(int i = 1 ; i <= n ; i ++)
    {
        // cout << w[h1] << " " << w[t1] << endl;
        // if(w[h1] < w[t1])
        // {
            if(w[i] <= q[hh + 1])
                q[hh--] = w[i];
            else
                q[tt++] = w[i];
        // }
        // else
            // if(w[t1] <= q[hh + 1]) 
            //     q[hh--] = w[t1--];
            // else
            //     q[tt++] = w[t1--];
    }
    // cout << hh << " " << tt << endl;
    for(int i = hh + 1 ; i <= tt - 1 ; i++) cout << q[i] << " ";
    cout << endl;

    return;
}


signed main()
{
    int _;cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
