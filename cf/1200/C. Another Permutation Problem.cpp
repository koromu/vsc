#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 200010;
void solve()
{//题目中可以得知, 我们要求两个东西, 一个是全部数字的最大值, 一个是全部最大值中的最大值
// 答案是总体最大减去单个最大, 为了是我们的答案最大, 我们需要使前面的元素最大, 后面的元素最小
//显然可见, 顺序排序时的总和最大, 只要有一个逆序的话总和就会变小
//在倒序的时候, 总和变小了, 但是最大值此时也变小了
//所以在数据小的情况下, 可以尝试枚举我们想要倒序的数字和顺序的数字
    int n;cin >> n;
    ll ans = 0, maxv;
    ll tmp = 0;

    for(int po = 0 ; po <= n ; po ++)
    {
        ans = 0;
        maxv = -1;
        // cout << "po :" << po << endl;
        for(int i = 1; i <= po ; i ++)
        {
            ans += i * i;//显示枚举正序
            // cout << "i * i : " << i * i << endl; 
            maxv = max(maxv, (ll)i * i);
        }
        for(int i = po + 1, j = n; i <= n ; i ++, j --)
        {
            ans += i * j;//此时计算逆序
            // cout << "j : " << j << endl; 
            maxv = max(maxv, (ll)i * j);
        }
        // cout << "ans : " << ans << " maxv : " << maxv << endl;
        tmp = max(tmp, ans - maxv);
    }
    cout << tmp << endl;
    return;
}

int main()
{
    int _;cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}