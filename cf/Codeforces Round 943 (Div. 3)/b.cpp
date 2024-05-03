#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}


void solve()
{
    int n, m;cin >> n >> m;
    string a , b;
    cin >> a >> b;
    int ans = 0;
    if(b.size() == 1) 
    {
        cout<< 0 <<endl;
        return ;
    }
    for(int i = 0, j = 0 ; i < b.size() ; i ++)
    {
        if(a[j] == b[i]) j++, ans ++;
    }
    cout << ans << endl;
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

