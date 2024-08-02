#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

int w[N];

void solve()
{
    int n, x, y; cin >> n >> x >> y;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
    }

    sort(w + 1, w + n + 1);
    i64 ans = 0;

    // 这个数组中有多少个, 对于每一个数找到右端点和左端点
    for(int i = 1 ; i + 1 <= n ; i ++)
    {
        i64 ll , rr;
        // 找1然后找一个最大的和一个最小的, 所以要找的是最小值的左端点, 小于等于这个值的左端点
        if(w[i] + w[n] < x) continue;

        if(w[i] + w[i + 1] > y) continue;// 如果加上下一个已经大了

        int l = i + 1, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(w[i] + w[mid] >= x)
            {
                r = mid;
            }
            else l = mid + 1;
        }
        ll = l;
        
        l = i + 1, r = n;
        while(l < r)// 找最大的
        {
            int mid = l + r + 1 >> 1;
            if(w[mid] + w[i] > y)
            {
                r = mid - 1;
            }
            else l = mid;
        }
        rr = r;
        // std::cout << "ll : " << ll << " rr : " << rr << "\n";
        ans += (rr - ll + 1);
    }

    std::cout << ans << "\n";
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