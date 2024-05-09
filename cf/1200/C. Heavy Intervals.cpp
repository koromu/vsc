#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;
typedef long long ll;
// 要求出一个区间差距最小的数组
// 首先在两个数组中找到距离最相近的值, 因为一个是左端点, 一个是右端点, 所以可以给左端点在另一个数组中找一个右端点
// 使用二分找到第一个大于这个值的值
// 这里可以使用lower_bound(x) 和 upper_bound(x)
// 其中一个求的是数组中第一个大于等于x的值, 一个是找到第一个大于x的值
// 所以这里是用的是第二个



// 所以区间长度要用multiset
void solve()
{
    // 我们在找到一个区间后, 需要直接去掉这两个数, 然后存到一个新数组中, 这个数组也需要排序
    int n, tmp;cin >> n;
    set<int> s1, s2;// 左右坐标不不会相同, 但是区间长度可能会相同
    multiset<ll> s, ans;// 而且区间大小也是可以重复的东西, 需要注意
    for(int i= 0 ; i < n ; i ++)
    {
        cin >> tmp;
        s1.insert(tmp);
    }
    for(int i = 0; i < n ; i ++)
    {
        cin >> tmp;
        s2.insert(tmp);
    }

    for(int i = 0 ; i < n ; i ++) cin >> tmp, ans.insert(tmp);

    while(!s1.empty())
    {
        int x1 = *s1.begin();
        s1.erase(x1);
        int x2 = *s2.upper_bound(x1);
        s2.erase(x2);
        s.insert(x2 - x1);// 经过计算是不用+1的
    }

    // for(auto i : s) cout << i << " ";
    // cout << endl;
    // 然后就是可以最小的区间长度, 权值直接用最大的
    long long res = 0;
    auto j = ans.end();
    j--;
    for(auto i = s.begin() ; i != s.end() ; i ++, j --)
        res += (*i * *j);
    cout << res << endl;
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