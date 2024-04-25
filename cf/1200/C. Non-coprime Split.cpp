#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#define long long int
using namespace std;
// typedef long long ll;

// int gcd(int a, int b)
// {
//     if(b == 0)
//         return a;
//     return gcd(b, a % b);
// }
int n1, n2;
bool get(int x)
{
    //把一个数拆成如果一个数可以被拆成a * b 那么这个数可以被拆成 (a - 1) * b 和 b 
    for(int i = 2; i <= x / i ; i ++)
    {
        if(x % i == 0)
        {
            //说明x是i的倍数也就是
            n1 = i, n2 = x - i;
            return true;//并且更新了答案
        }
    }//如果这个x是个素数
    return false;
}

void solve()
{
    int l, r;
    cin >> l >> r;
    for(int i = l ; i <= r ; i ++)//从l ~ r 中找到一个合数
    {
        if(get(i))
        {
            //找到了
            cout << n1 << " " << n2 << endl;
            return ;
        }//如果一直没找到呢
    }
    cout << -1 << endl;
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
