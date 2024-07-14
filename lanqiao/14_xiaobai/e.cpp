#include <iostream>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int mod = 998244353;
const int N = 10;
int f[N];

int pow(int a, int b, int mod)
{
    int ans = 1;
    while(b)
    {
        if(b & 1)
            ans = a * ans % mod;
        a = a * a % mod ;
        b >>= 1;
    }
    return ans % mod;
}

signed main()
{
    int len = 0, ans = 0;
    for(int i = 1 ; i <= 9 ; i ++)
    {
        cin >> f[i];
        len += f[i];
    }
    // cout << "len : " << len << endl;
    // 枚举长度
    for(int i = 1 ; i <= len ; i ++)// 1e5
    {
        // 每次加上10^(i - 1)
        // 枚举9个数， 每次加上个cj * j
        for(int j = 1; j <= 9 ; j ++)
            ans = (ans + f[j] * j * pow(10, i - 1, mod)) % mod;
    }    
    // 次数
    cout << ans << endl;
    return 0;
}
