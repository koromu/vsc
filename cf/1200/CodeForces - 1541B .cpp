#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 200010;

pii w[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i].first;
        w[i].second = i;
    }
    // 存下所有的数字
    sort(w + 1, w + n + 1);
    // for(int i = 1 ; i <= n ; i ++) cout << w[i].first << " " << w[i].second << endl;
    int ans = 0;
    for(int i = 1; i <= n - 1; i ++)
    {
        // 枚举每一个数, 下标和的最大值就是4e5
        // 一个a的大小最大也是2e5
        for(int j = i + 1 ; j <= n; j ++)
        {
            int x = w[i].first * w[j].first;
            if(x > 2 * n) break;// 都不需要往后看了
            if(w[i].first * w[j].first == w[i].second + w[j].second)
                {
                    // cout << "w[i].first : " << w[i].first << " w[j].first : " << w[j].first << " w[i].second : " << w[i].second << " w[j].second : " << w[j].second << endl;
                    ans ++;
                }
        }

    }
    cout << ans << endl;
}

signed main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}