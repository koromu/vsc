#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 2e5;
int w[N];
int f[N];
unordered_map<int, int> ha;

void solve()
{
    int n, m, x; cin >> n >> m >> x;
    // 已知一个坐标, 然后求这个坐标其他的值
    int y1 = x / n + 1, x1 = x % n;
    if(x % n == 0)
    {
        x1 = n;
        y1 -= 1;
    }
    // cout << x1 << " " << y1 << endl;
    cout << y1 + (x1 - 1) * m << endl;
    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}