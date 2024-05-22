#include <iostream>

using namespace std;
typedef unsigned long long  ull;
const int N = 200010;

int w[N], d[N];

void solve()
{
    ull n, f, a, b; cin >> n >> f >> a >> b;
    for(int i = 1 ; i <= n ; i ++) cin >> w[i];

    // 开机需要b, 持续开机需要a
    // 就判断一个点到一个点之间的距离, 看看b 和 a * 长度那个大
    // 所以需要一个差分数组, 计算出两点之间的距离
    for(int i = 1 ; i <= n ; i ++)
    {
        d[i] = w[i] - w[i-1];
    }
    ull ans = 0;
    for(int i = 1 ; i <= n ; i ++ )
    {
        ans += min(b, (ull)d[i] * a);
    }
    if(ans < f) puts("YES");
    else puts("NO");

}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}