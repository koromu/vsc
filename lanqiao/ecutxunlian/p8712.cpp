#include <iostream>
#include <set>

using namespace std;
typedef pair<int, int> pii;// 存点的下标
typedef long long ll;

const int N = 100010;

ll w[N];
unsigned long long ha[12][N];// 表示10的i次方, 然后余数是j

ll qmi(int a, int b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1; 
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++) cin >> w[i];

    for(int i = 1; i <= n ; i ++)
    {
        // 枚举每一个数
        ll t = w[i];// 得到次方
        for(int j = 0 ; j <= 10 ; j ++)
        {
            ha[j][(t * qmi(10, j)) % k] ++;// 计算出次数 
        }
    }

    unsigned long long ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        // 枚举每一个数
        // 然后把这个数放在后面
        // 然后枚举前面的数字
        int len = to_string(w[i]).size();// 直接得到这个数字的长度
        // 然后枚举
        ll t = w[i] % k;// 先求出后面的这个数的余数
        // 然后求出我们前面要的数字的余数
        ll obj = (k - t) % k;// 前面的数字需要和后面的数字的余数和是k的倍数, 所以这个数的就是-t % k的余数
        // cout << w[i] << " len : " << len << endl;
        // 如果123 和 123000的余数相同的话, 那么就减1
        ans += ha[len][obj];// 这个余数出现的次数, 要不要除去自己

        if(((qmi(10, len) * w[i]) + w[i] ) % k == 0) ans --;// 如果这两个数的合数是k的倍数的话
    }
    cout << ans << endl;
    return 0;
}// 90
