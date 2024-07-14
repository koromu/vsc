#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int f[N];

void solve()
{
    // 有一个原数组，然后要我们分成两个可以不连续的子序列
    // 下标从1开始，然后一个数字中1 ~ m - 1的元素中b[i] < b[i+1]
    // 然后要这个i最小
    // 所以要我们处理数组

    // 贪心的想s数组和t数组
    // 两个数组我们们不能够打乱主要的顺序，所以直接按照读入的顺序
    // 非常巧妙地只考虑每个数组中的最最最最后一个元素
    // 那么开始的两个数,大的放s中, 小的放t中
    // 有几种可能

    // 有可能大于s和t, 那么放到较小的那个里面中, 降低下次可能产生递增数列的可能性
    // 可能同时小于s和t的最后一个元素, 那么加到更小的那个里面, 保护最大值, 也就是为了保证可以让下一个递增的概率更小
    // 可能大于其中一个小于另一个, 那么直接加到s和t中较大那个里面
    int n; cin >> n;
    vector<int> s = {}, t = {};
    s.push_back(1e9);
    t.push_back(1e9);
    int ans = 0; // 记录两个数组的最后一个元素的大小

    for(int i = 0 ; i < n ; i ++)
    {// 如果两个相等的话就放第一个吧
        int tmp ; cin >> tmp;
        if(tmp > *(s.end() - 1) && tmp > *(t.end() - 1))
        {
            if(*(s.end() - 1) > *(t.end() - 1)) t.push_back(tmp);
            else s.push_back(tmp);
        }
        else if(tmp >= *(s.end() - 1) && tmp > *(t.end() - 1))
        {
            s.push_back(tmp);
        }
        else if(tmp > *(s.end() - 1) && tmp >= *(t.end() - 1))
        {
            t.push_back(tmp);
        }
        else if(tmp <=*(s.end() - 1)&& tmp > *(t.end() - 1))
        {
           s.push_back(tmp);
        }
        else if(tmp > *(s.end() - 1)&& tmp <= *(t.end() - 1))
        {
            t.push_back(tmp);
        }
        else// tmp 同时小于s和t的话, 那就插入稍微小一点的的那个里面
        {
            if(*(s.end() - 1) > *(t.end() - 1)) t.push_back(tmp);
            else s.push_back(tmp);
        }
    }
    // cout << (int)s.size() << " " << (int)t.size() << endl;
    for(int i = 1 ; i <= (int)s.size() - 2; i ++)// 经典size返回的是无符号整形
    {
        // cout << s[i] << " ";
        if(s[i] < s[i + 1]) ans ++;
    }
    // cout << endl;
    for(int i = 1 ; i <= (int)t.size() - 2; i ++)
    {
        // cout << t[i] << " ";
        if(t[i] < t[i + 1]) ans ++;
    }
    // cout << endl;
    cout << ans << endl;
    // cout << endl;
}

signed main()
{
    int _; cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
