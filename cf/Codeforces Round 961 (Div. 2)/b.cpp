#include <bits\stdc++.h>
#define int long long
using namespace std;

const int N = 20;
int w[N];
int q[N * 2];
int hh = 0, tt = -1;

void solve()
{
    int n, m; cin >> n >> m;
    hh = 0, tt = -1;
    for(int i = 1 ; i <= n ; i ++) 
        cin >> w[i];
    sort(w + 1, w + 1 + n);

    int ans = 0;
    q[++tt] = w[1];// 存进去第一个数
    int tmp = w[1];
    int ll = w[1], nn = w[1];
    for(int i = 2 ; i <= n ; i ++)
    {
        // cout << tt << endl;
        // 记录这个队列里面的最大值和最小值
        if(w[i] - ll > 1)
        {
            // 如果差值大于1了, 那么就把前面的删掉
            while(q[hh] - w[i] > 1)
            {
                tmp -= q[hh++];
            }
            ll = q[hh];
        }
        else if(w[i] + tmp > m)
        {
            // 如果大于m了的话
            while(tmp + w[i] > m)
            {
                tmp -= q[hh++];
                ll = q[hh];// 变成当前的首元素
            }
        }
        // 合法情况
        // 处理完后可以插入这个元素了
        q[++tt] = w[i];
        nn = w[i];
        tmp += w[i];
        ans = max(ans, tmp);
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
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());

//     int ans = 0, sum = 0;
//     int l = 0;
//     for (int r = 0; r < n; ++r) {
//         sum += a[r];
//         while (a[r] - a[l] > 1) {
//             sum -= a[l++];
//         }
//         while (sum > m) {
//             sum -= a[l++];
//         }
//         ans = max(ans, sum);
//     }

//     cout << ans << endl;
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }
