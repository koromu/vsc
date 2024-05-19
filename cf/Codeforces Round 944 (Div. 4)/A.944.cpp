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
    int x, y;
    cin >> x >> y;
    if(x > y) cout << y << " " << x << endl;
    else cout << x << " " << y << endl;
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

