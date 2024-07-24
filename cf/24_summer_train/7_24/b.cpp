#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 2e5 + 10;

int lowbit(int x)
{
    return x & (-x);
}

void solve()
{
    int n; cin >> n;
    int cc = n / 2021;
    for(int i = 1 ; i <= cc ; i ++)
    {
        if((n - 2021 * i) % 2020 == 0)
        {
            puts("YES");
            return;
        }
    }
    for(int i = 1 ; i <= n / 2020 ; i ++)
    {
        if((n - 2020 * i) % 2021 == 0)
        {
            puts("YES");
            return;
        }
    }
    puts("NO");
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}