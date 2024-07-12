#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;

int a[N];
bool st[N];

void solve()
{       
    int n; cin >> n;
    for(int i = 0; i < n ; i ++)
    {
        cin >> a[i];
    }
    for(int i = n - 1 ; i - 1 >= 0 ; i --)
    {
        if(a[i] > a[i-1])
        {
            for( ; i - 1 >= 0 ; i --)
            {
                if(a[i] < a[i - 1])
                {
                    cout << i << endl;
                    return ;
                }
            }
            cout << 0 << endl;
            return;
        }
    }
    cout << 0 << endl;
    // 要处理之后左边的数组是上升，右边的数组是下降
}

signed main()
{
    int _ ; cin >> _;
    while(_--) solve();
    return 0;
}
