#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef unsigned long long  ull;
const int N = 200010;

int a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];
    map<pair<int, int>, int> p1, p2, p3;// 记录一对出现的次数
    map<tuple<int, int, int>, int> p0;// 记录一个出现过的三元组
    ull ans = 0;// 记录答案出现的次数, 直接统计两个元素相同的次数有多少, 每次再把这两个元素是这样的情况加进去
    // 有可能碰到相同的三元组, 所以需要重复对的次数, 也就是这个数组出现的次数
    // 所以需要记录每个三元组出现的次数
    for(int i = 1 ; i <= n ; i ++)
    {
        // 记录当前区间的三元组的两个位置的值出现的次数
        if(i >= 3)
        {
            // 区间中已经有了三个元素
            // 记录三个位置中, 一对的情况加一, 也就是下次有一个新的对出现, 就可以直接加上这两个位置相同的个数, 然后在最后去掉重复的个数
            ans += p1[{a[i - 2], a[i - 1]}]++;
            ans += p2[{a[i - 2], a[i]}]++;
            ans += p3[{a[i - 1], a[i]}]++;
            ans -= 3 * p0[{a[i - 2], a[i - 1], a[i]}] ++;
        }
    }    
    cout << ans << endl;
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