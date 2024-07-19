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

void solve()
{
    string a; cin >> a;
    int ca = 0, cb = 0, cc = 0;
    for(int i = 0 ; i < a.size() ; i ++)
    {
        if(a[i] == 'A')
        {
            ca ++;
        }
        else if(a[i] == 'B')
        {
            cb++;
        }
        else
        {   
            cc++;
        }
    }

    if(ca + cc == cb)puts("YES");
    else puts("NO");

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
