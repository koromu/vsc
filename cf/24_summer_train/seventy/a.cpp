#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int w[N];

void solve()
{
    int n; cin >> n;
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        int tmp; cin >> tmp;
        if(ans >= 0 && (tmp == 1 || tmp == 3))
        {
            ans++;
        }
        else{
            // ans--;
        }
    }
    cout << ans << endl;
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
