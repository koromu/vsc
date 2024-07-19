#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 500010;

void solve()
{
    // 偶数向左, 奇数向右
    int x, n; cin >> x >> n;
    // 如果x是奇数, 那么接下来是
    int c2 = n % 4;
    int ans = x;
    int ji[4] = {1, -1, -1, 1};
    int ou[4] = {-1, 1, 1, -1};
    if((x % 2 + 2) % 2 == 1)
    {
        int sta = n - c2 + 1;
        for(int i = 0 ; i < c2 ; i ++)
        {
            ans += (ji[i] * sta);
            sta++;
        }
    }
    else
    {
        int sta = n - c2 + 1;
        for(int i = 0 ; i < c2 ; i ++)
        {
            ans += (ou[i] * sta);
            sta++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    int _; cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
