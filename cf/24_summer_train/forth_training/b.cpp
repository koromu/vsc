#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;
int n, m, k;
string a; 

void solve()
{   
    int a, b; cin >> a >> b;
    int ans = 0;
    if(a > b) swap(a, b);
    // a < b
    if(b >= 3 * a)
    {
        cout << a << endl;
    }
    else if(b < 3 * a)
    {
        cout << (a + b) / 4 << endl;
    }
    return ;
}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
