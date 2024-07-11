#include <iostream>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;


void solve()
{   
    int a, b; cin >> a >> b;
    if(a == 0)
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        // 有至少1个1
        cout << b * 2 + a + 1 << endl;
    }
    // 有很多个1, 有很多个2, 首先1 ~ a肯定都是可以组成的
    // 然后
    return;
}



signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
