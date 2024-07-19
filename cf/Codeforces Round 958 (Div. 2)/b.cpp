#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;

// int w[N];

void solve()
{   
    int c1 = 0, c0 = 0;
    int n; cin >> n;
    string a; cin >> a;
    a = '#' + a;
    for(int i = 1 ; i <= a.size() ; i ++)
    {
        if(a[i] == '0')
        {
            for(int j = i; j <= a.size() ; j ++)
            {
                if(a[j] != a[j + 1])
                {
                    // 说明0串到头了
                    c0 ++;
                    i = j;
                    break;
                }
            }
        }
        if(a[i] == '1') c1 ++;
    }// 统计出有多少0串
    // cout << "c1 : " << c1 << " c0 : " << c0 << endl;
    if(c1 >= c0 + 1) puts("YES");
    else puts("NO");
}
signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
