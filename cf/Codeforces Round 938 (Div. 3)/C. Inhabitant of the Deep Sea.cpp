#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 10;
ull w[N], f[N], s[N];
ull n, k;
void solve()
{
    memset(s, 0, sizeof s);
    memset(f, 0, sizeof f);
    ull n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        f[i] = w[i] + f[i - 1]; // 前缀和
    }
    for (int i = n; i >= 1; i--)
    {
        s[i] = s[i + 1] + w[i]; // 后缀和
    }
    if (f[n] <= k)
    {
        cout << n << endl;
        return;
    }
    ull l = k / 2, r = l; // l = k = 99999999999 / 2
    if (k % 2 != 0)
        l++;
    int ans = 0;
    int i = 1, j = n;
    while (f[i] <= l && i < j)
        i++, ans++; // 退出是得到的是第一个大于等于l的下标
    while (s[j] <= r && i < j)
        j--, ans++; // 同上
    cout << ans << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}