#include <iostream>
#include <algorithm>
#include <queue>
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
    int n;; cin >> n;
    if(n == 2)
    {
        puts("NO");
        return;
    }
    int ans = 0;
    while(n)
    {
        n -= lowbit(n);
        ans  ++;
    }
    if(ans >= 2)puts("YES");
    else puts("NO");
    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}