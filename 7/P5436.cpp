#include <iostream>

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

void solve()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << endl;
        return ;
    }
    cout << lcm(n, n - 1) << endl;;

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