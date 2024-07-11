#include <iostream>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;

void solve()
{   
    // g是不大于m的和
    // f是不小于k的和
    // 要f - g最大
    int n, m, k; cin >> n >> m >> k;
    int rn = n;
    // 长度都是n
    // g[i]是长度为i的前缀和
    // f[i]是长度为i的前缀和
    // 所以第一个数是n倍, 第二个数是n-1倍, 第n个数是1倍
    for(int i = 0 ; i < rn - k + 1 ; i ++)
    {// 打印m个值, 从大到小
        cout << n-- << " ";
    } 
    // cout << endl;
    // cout << "n: " << n << endl; 
    for(int i = 0 ; i < k - m  - 1 ; i ++)
    {
        cout << n -- << " ";
    }
    // cout << endl;
    // cout << "n: " <<  n << " " << m << endl;
    for(int i = 1 ; i <= m ; i ++)
    {
        cout << i << " ";
    }
    cout << endl;
// }

}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
