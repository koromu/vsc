#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    //明显可见, 两个数的最小公倍数的倍数的位置, 全都会被抵消掉, 然后一加一减可知, 大的尽量放加的里面, 然后减的尽量放小的, 
    //所以从小到大的选要减的数, 从大到小的选要加的数, 然后还需要有用来抵消的数
    //先算出有多少个最小公倍数的倍数, 用n以内的x的倍数个数减去得到能加的数, n以内y的倍数的个数减去得到的就是能减的数
    //x的倍数包括x和y的最小公倍数的倍数, y的倍数包括y的最小公倍数的倍数
    //所以算出减去两遍x和y的最小公倍数得到的就是需要加和需要减的数
    ll x_num = n / x;
    ll y_num = n / y;
    ll xy_num = n / lcm(x, y);//最小公倍数的倍数的个数, 也就是算出g * lcm(x, y)的g最大是多少

    ll a_num = x_num - xy_num;// 要求的是可以加上的数的个数, x - xy_num啥也不是
    ll d_num = y_num - xy_num;//
    //从前往后和从后往前遍历得到解, 直接用等差和求和
    //先算加的, 首项是n, 公差是-1, 项数是a_num, 首项加末项乘以项数除以2
    //再算减的, 首项是1, 公差是1, 项数是d_num
    ll a_sum = (n + (n - a_num + 1)) * a_num / 2;
    ll d_sum = (1 + d_num) * d_num / 2;  
    // cout << "a_num : " << a_num << " d_num : " << d_num << endl; 
    cout << a_sum - d_sum << endl;
}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}