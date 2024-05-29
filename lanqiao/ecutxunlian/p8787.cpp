#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <math.h>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 200010;

pii w[N];// first存高度, second存次数

signed main()	
{
    int n; cin >> n;
    // 对于每一个竹子看, 砍到1之前, 需要砍多少次, 然后存到一个数组中
    // 存下能砍的次数, 和现在的高度
    // 只有高度相同的时候才能砍一片
    // 也就是当 当前这一个的高度 和 后一个高度 相同的时候, 我们的ans可以先不+1, 等不相同的时候再+1
    // 然后对于当前最高的那个这个可以砍的次数, 就在这次就砍了, 因为这个是最高的, 如果高度不同, 那么只砍一个也没用
    int maxv = -1;
    for(int i = 1; i <= n; i ++)
    {
        cin >> w[i].first;
        int tmp = w[i].first;
        while(tmp != 1)
        {
            tmp = sqrt((tmp / 2) + 1);
            w[i].second ++;
        }
        maxv = max(w[i].second, maxv);
    }
    // for(int i = 1; i <= n; i ++) cout << w[i].second << " " << w[i].first << endl;
    int ans = 0;
    for(int i = maxv ; i >= 1 ; i --)
    {
        for(int j = 1; j <= n ; j ++)
        {
            // 对于每一个可以砍的次数进行枚举, 如果不存在这个次数, 那么被特判
            if(w[j].second == i)
            {
                // 如果被砍次数相同了, 那么就看一下是不是和后面那个高度相同, 如果不同, 那么需要单独砍一次, 如果相同那么就继续往后看, 知道不同, 如果全部都相同的话, 特判一下
                if(w[j].first != w[j + 1].first)
                    ans ++;
                w[j].second --;
                w[j].first = sqrt((w[j].first / 2) + 1);
            }
            // cout << w[j].first << " " << w[j].second << endl;
        }
    }
    cout << ans << endl;
    return 0;
}