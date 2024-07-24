#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> piiii;
const int N = 3e3 + 10;
int w[N];
int f[N];
// 所以我们要存一个区间起点和终点, 然后还有长度
unordered_map<int, int> ha;
vector<piiii> v1;

bool cmp(piiii a, piiii b)
{
    if(a.second == b.second)
    {
        if(a.first.first == b.first.first)
            return a.first.second < b.first.second;
        else return a.first.first < b.first.first;
    }
    return a.second < b.second;
}

void solve()
{
    int n; cin >> n;
    // f[i]表示删除i得到的最大分数
    // 所以可以递归求, 因为求大的区间要用到小的区间
    // 然后直到最小的就是考虑删除这个区间但是里面没有其他的完整的区间
    // 处理好了最小的之后就可以往后推了, 对于一个区间之间有其他的完整的区间的区间
    // 我们要考虑是不是要选择加上这个区间
    // 或者不加上这个区间, 而是直接作为这个区间的元素直接进行贡献, 所以一个f[i]我们要遍历这个区间, 进行dp一下, 然后dp[r_i]就是f[i]
    // 所以发现我们要用到的小区间, 为了不递归我们现选出所有区间, 然后进行排序成从小到大，因为区间小的一定在区间大的里面

    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
        if(ha[w[i]])
            v1.push_back({{ha[w[i]], i}, {i - ha[w[i]], w[i]} });
        else ha[w[i]] = i;// 对这个数存下第一个下标, 然后再碰到另一个点的时候存下另一个下标
    }
    v1.push_back({{-1, n + 1}, {n + 2, 0}});
    // 然后从小到大遍历区间
    std::sort(v1.begin(), v1.end(), cmp);

    for(int i = 0 ; i < v1.size() ; i ++)
    {
        int l = v1[i].first.first, r = v1[i].first.second, len = v1[i].second.first, val = v1[i].second.second;
        int dp[N];
        for(int j = l; j <= r; j ++)
        {// 首先取出来了一个区间, 然后这个区间的两边的值就是这个区间中的贡献
            // 然后每一个点可以选可以不选, 选的话这个点的左端点一定得到这个l的右边
            dp[j] = dp[j - 1] + val;
            if(ha[w[j]] > l)// 然后要看这个j对应的左端点, 左端点是
            {
                dp[j] = max(dp[j], dp[j - 1] + f[w[j]]);
            }
        }
        f[i] = dp[r];
    }
    cout << f[0] << endl;
    return ;
}


signed main()
{
    int _ = 1; // cin >> _;
    while(_--) solve();
    return 0;
}