#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int a[3];

void solve()
{
    for(int i = 0 ; i < 3 ; i ++) cin >> a[i];

    // sort(a, a + 3);

    int ans = 0;
    // ans += a[0];
    // a[2] -= a[0];
    // a[0] = 0;

    if(abs((a[2] - a[0]) - a[1]) % 2 != 0) {
        puts("-1");
        return;
    }
    // 把错误的特判掉

    if(a[0] + a[1] >= a[2])
    {
        cout << a[2] + (a[0] + a[1] - a[2]) / 2 << endl;
    }
    else
    {
        ans = a[0];
        a[2] -= a[0];
        a[0] = 0;
        ans += min(a[2], a[1]);
        cout << ans << endl;
    }
    

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

