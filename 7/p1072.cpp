#include <iostream>
#include <algorithm>
using namespace std;

// int gcd(int a, int b)
// {
//     if(b == 0) return a;
//     else gcd(b, a % b);
// }



int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}
void solve()
{
    int a0, a1, b0, b1;
    int ans = 0;
    cin >> a0 >> a1 >> b0 >> b1;
    for(int i = a1 ; i <= b1 ; i ++ )   
    {
        if(__gcd(i, a0) == a1 && lcm(i, b0) == b1)
            ans ++;
    }
    cout << ans << endl;
}

int main()
{
    init();

    return 0;
}