#include <iostream>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int a[N];

void solve()
{   
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];

    sort(a + 1, a + n  + 1);
    if(a[n] - a[n-1] > 1) puts("NO");
    else puts("YES");
    return; 
}



signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
