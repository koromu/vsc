#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

pair<int, int> v1[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> v1[i].first;
    for(int i = 1 ; i <= n ; i ++)
        cin >> v1[i].second;
    
    // for(int i = 1 ; i <= n ; i ++) cout << v1[i].first << " " << v1[i].second << "\n";

    int sum1 = 0, sum2 = 0;
    int sumfu = 0, sumz = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        // 四种情况, 如果都是0, 那么随便个都行
        int x1 = v1[i].first, x2 = v1[i].second;
        // cout << x1 << " " << x2 << "\n";
        if(x1 == 0 && x2 == 0)
        {
            // 随便哪个
            continue;
        }
        else if(x1 == 1 && x2 == 1)
        {
            // 都是1的话看哪个少
            sumz ++;
        }
        else if(x1 == 1 || x2 == 1)
        {
            // 哪个是1就去哪个
            if(x1 == 1) sum1++;
            else sum2++;
        }
        else if(x1 == -1 && x2 == -1)
        {
            // 如果两个都是负数
            // 存起来以后处理
            sumfu ++;
        }
        else if(x1 == -1 || x2 == -1)
        {
            continue;// 不用管
        }
    }
    // cout << sum1 << " " << sum2 << "\n";
    // cout << sumz << "\n";
    while(sumz)
    {
        if(sum1 < sum2) sum1++;
        else sum2++;
        sumz--;
    }
    while(sumfu)
    {
        if(sum1 > sum2) sum1--;
        else sum2--;
        sumfu--;
    }


    cout << min(sum1, sum2) << "\n";
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}