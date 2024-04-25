#include <iostream>

using namespace std;
typedef long long ll;
const int N = 10010;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

ll lcd(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int w[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> w[i];

    

    return 0;
}