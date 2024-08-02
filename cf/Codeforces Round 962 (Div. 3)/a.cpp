#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 2e5 + 10;

int w[N];

void solve()
{
    int n;; cin >> n;
    int c1 = n / 4;
    if(n % 4 != 0) c1 ++;
    cout << c1 << endl;
    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}