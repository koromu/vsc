#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}


void solve()
{
    int n;cin >> n;
    int ans = 0, res = 0, i;
    for(i = 1 ; i < n  ; i ++)
    {
        if(gcd(i, n)+ i > ans ) ans = max(gcd(i, n)+ i, ans), res = i;
    }
    cout << res << endl;
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

