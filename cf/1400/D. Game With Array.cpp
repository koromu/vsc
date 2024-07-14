#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;

signed main()
{
    int n, s; cin >> n >> s;
    // 先判断
    // 现在合法的范围内枚举k, 然后看s-k在不在范围内
    int l = n, r = s - n;
    for(int i = l ; i <= r ; i ++)
    {
        if(s - l >= l && s - l <= r)
        {
            puts("YES");
            for(int i = 0 ; i < n - 1; i ++)
            {
                cout << 1 << " ";
            }
            cout << s - n + 1 << endl;
            cout << i << endl;
            return 0;
        }
    }
    puts("NO");
    return 0;
}
