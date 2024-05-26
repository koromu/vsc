#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <math.h>

#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 200010;


void solve()
{
    int n;
    cin >> n;
    int ans = 0, tmp;
    for(int i = 0 ; i < n ; i ++) {
        cin >> tmp;
        ans += tmp;
    }

    if((int)sqrt(ans) * (int)sqrt(ans) == ans )
    {
        puts("YES");
    }
    else puts("NO");
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