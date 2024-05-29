#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 100010;

int w[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    if(n <m )puts("NO");
    if(n >= m)
    {
        // 如果操作次数大于等于m的话
        if((n - m) % 2 == 0)
        {
            puts("YES");
        }
        else puts("NO");
        return ;
    }
}

signed main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}