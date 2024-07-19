#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int w[N], a[N], b[N];
void solve()
{
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> w[i];
    }
    sort(w + 1, w + n + 1);
    // a[i - 1] = 0;
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     b[i] = w[i] - w[i-1];// 差值
    //     a[i] = - w[i] + a[i - 1];// 前缀
    //     // cout << "w[i - 1]  :" << w[i-1] << " w[i] : " << w[i] << " " <<  a[i] << endl;
    //     cout << a[i] << "~";
    // }
    // cout << endl;
    // for(int i = 2 ; i <= n ; i ++)
    //     cout << b[i] << " ";
    // cout << endl;
    // for(int i = 1 ; i <= n ; i ++)
    //     cout << - w[i] << " ";
    // cout << endl;
    // int pos = n;
    // for(int i = 1 ; i + 1 <= n ; i ++)
    //     if( b[i + 1] - w[i] > 0)
    //     {
    //         pos = i + 1;
    //         cout << "pos : " <<  pos << endl;
    //         break;
    //     }
    // // 得到了我们最大的最小值的点
    
    // cout << w[pos] + a[pos - 1] << endl;
    int maxv = -1e9 - 10;
    for(int i = 1 ; i <= n ; i ++)
    {
        maxv = max(maxv, w[i] - w[i - 1]);
    }
    cout << maxv << endl;
}

signed main()
{
    int _; cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
