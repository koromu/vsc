#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{   
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    if(a < b) swap(a, b);
    while(a - b >= 2 * c)
    {
        //退出的时候相差小于2 * c
        a -= c;
        b += c;
        ans ++;
    }
    if(a - b > 0) ans ++;
    cout << ans << endl;
    return;
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
