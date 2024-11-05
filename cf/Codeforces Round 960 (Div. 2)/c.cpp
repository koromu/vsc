#include <bits/stdc++.h>
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

int w[N];
int pre[N];
int b[N];

void solve()
{
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n ; i ++)
    {
        cin >> w[i];
        ans += w[i];// 这厮第一遍的答案
        // b[i] = 0;
    }
    // cout << "ans : "  << ans << "\n";
    // 第一次循环就会产生一个新的数组, 这个数组可以模拟出来, 第二次循环也会产生一个新的数组, 然后第三次就开始一个一个减1了
    // 此时求出一个前缀和, 枚举右端点, 每次少加1个位置就行了
    // 维护一个最大值, 如果没有那就是0, 如果出现了一个出现过的数, 那么尝试更新最大值, 如果没有出现过那么标记一下
    for(int k = 1 ; k <= 2 ; k ++)
    {
        int st[N] = {0};
        int maxv = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
            if(!st[w[i]])
            {
                st[w[i]]++;
            }
            else maxv = max(maxv, w[i]);
            w[i] = 0;
            if(maxv)
            {
                w[i] = maxv;// 尝试更新完了就可以试着赋值了, 否则就是直接是0, 也就不用管
                ans += w[i];// 这两边就在这里面更新了
            }
            // cout << "ans : " << ans << "\n";
        }
        // cout << "ans : " << ans << "\n";
    }
    int len = 0;
    // 如果还有值得话, 那么看看还有多长
    for(int i = 1 ; i <= n ; i ++)
    {
        if(w[i] != 0)
        {
            len = i;// 如果全是0那么就是0
            break;
        }
    }

    if(!len)
    {
        cout << ans << "\n";
        return;
    }

    // for(int i = 1 ; i <= n ; i ++) std::cout << w[i] << " ";
    // cout << "\n";

    for(int i = 1 ; i <= n ; i ++)
    {
        pre[i] = pre[i - 1] + w[i];
        // std::cout << pre[i] << " ";
    }

    for(int i = n - 1 ; i >= len ; i --)
    {
        ans += pre[i];
    }

    // cout << "\n";

    cout << ans << "\n";


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