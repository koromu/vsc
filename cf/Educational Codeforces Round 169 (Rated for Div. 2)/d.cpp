#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
pair<int, int> t[N];
int n;
// vector<int> v1[N];
int w[N][6];// 第i个点到其他颜色的最小值

void solve()
{
    int q; cin >> n >> q;
    string a;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a;
        if(a[0] == 'B')
        {
            t[i].first = 1;
        }
        else if(a[0] == 'G')
        {
            t[i].first = 2;
        }
        else if(a[0] == 'R')
        {   
            t[i].first = 3;
        }
        else if(a[0] == 'Y')
        {   
            t[i].first = 4;
        }

        if(a[1] == 'B')
        {
            t[i].second = 1;
        }
        else if(a[1] == 'G')
        {   
            t[i].second = 2;
        }
        else if(a[1] == 'R')
        {   
            t[i].second = 3;
        }
        else if(a[1] == 'Y')
        {   
            t[i].second = 4;
        }
        // if(a[0] == 'B')
        // 相同颜色之间到达是固定的距离, 那么一个颜色到另一个颜色之间的距离
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        // 对于每一个点
        for(int j = i ; j >= 1 ; j --)
        {
            if(t[j].first == t[i].first || t[j].first == t[i].second || t[j].second == t[i].first || t[j].second == t[i].second)
            {
                // 相同颜色之间到达是固定的距离, 那么一个颜色到另一个颜色之间的距离
                w[i][t[j].first] = min(w[i][t[j].first], abs(i- j));
            }
        }
        for(int j = i ; j <= n ; j ++)
        {
            if(t[j].first == t[i].first || t[j].first == t[i].second || t[j].second == t[i].first || t[j].second == t[i].second)
            {
                // 相同颜色之间到达是固定的距离, 那么一个颜色到另一个颜色之间的距离
                w[i][t[j].first] = min(w[i][t[j].first], abs(i- j));
            }
        }
    }
    while(q--)
    {
        int x, y; cin >> x >> y;
        // 读入两个点, 然后如果这两个点不能直接到达
        // 如果两个点无相同颜色传送门
        if(t[x].first != t[y].first && t[x].first != t[y].second && t[x].second != t[y].first && t[x].second != t[y].second)
        {
            // 枚举中间传送门
            for(int i = x ; i >= 1 ; i --)
            {

            }
            for(int i = x ; i <= n ; i ++)
            {
                // 枚举所有其他的点
            }
        }
        else 
        {
            // 如果有一个想用的可以直接算出来
            cout << abs(x - y) << "\n";
        }

    }

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