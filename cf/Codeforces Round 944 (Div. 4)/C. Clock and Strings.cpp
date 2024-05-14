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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int mod = 12;
    if(a > b) swap(a, b);// a < b
    if(c > d) swap(c, d); // c < d

    if( c > a && c < b )
    {
        // c的范围是在a, b之中的话
        // 如果d也在ab之间的话, 那么就不会相交
        if(d > a && d < b)
        {
            // 合法的
            puts("NO");
        }
        else puts("YES");
    }
    else
    {
        // 如果左端点不在的话
        if(d > a && d < b)
        {
            puts("YES");
        }
        else puts("NO");
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

