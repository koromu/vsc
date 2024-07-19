#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;

int w[N];

void solve()
{   
    int n, k; cin >> n >> k;
    int ans = 0;
    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
    while(n > k)
    {
        ans ++;
        // if(k >= n) break;
        n -= (k - 1); 
    }
    ans ++;
    cout << ans << endl;
}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
