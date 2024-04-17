#include <iostream>

using namespace std;

void solve()
{
    int a, b, n;
    cin >> n >> a >> b;
    if(2 * a >= b)
    {
        if(n % 2 == 0)
            cout << (n / 2) * b << endl;
        else cout << (n / 2) * b + a << endl;
    }
    else cout << a * n << endl;
    return ;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}