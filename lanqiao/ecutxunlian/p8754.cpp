#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main()
{
    ll n;  
    cin >> n;
    // 对n进行质因数分解
    vector<pii> v1;
    for(ll i = 2 ; i < n / i; i ++)
    {
        ll s = 0;
        if(n % i == 0)// 如果能被整除的话, 是他的倍数
            while(n % i == 0)
            {
                n /= i;
                s++;
            }
        if(s)
            v1.push_back({i, s});
    }
    
    if(n)
    {
        v1.push_back({n, 1});
    }

    // 然后得到了一个质因数的式子
    ll ans = 1;
    // 我们把每一个质因数的指数是奇数的数字都到ans上, 然后得到的ans和n就可以组成一个可以完全平方的数字了, 那为什么是最小的呢
    // 因为少乘了一个就不是完全平方数了
    for(int i = 0 ; i < v1.size() ; i ++)
    {
        if(v1[i].second % 2 == 1)
            ans *= v1[i].first;
    }

    cout << ans << endl;
    return 0;
}// 全都要long long 也就是要#define int long long