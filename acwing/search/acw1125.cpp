#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

#define int long long
using namespace std;

typedef pair<int, int> pii;
const int N = 150;


char g[N][N];// 表示点之间的关系
int n;
pii a[N];// 存下下标
double d[N][N];
double maxd[N];// 每个点到一个点的最大距离/

double get_dis(pii a, pii b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

signed main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i].first >> a[i].second;

    for(int i = 0 ; i < n ; i ++)
        cin >> g[i];

    // Floyd必备的一个初始化
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < n ; j ++)
            if(g[i][j] == '1') d[i][j] = get_dis(a[i], a[j]);
            else d[i][j] = 1e20;// 对于double可能要存更大的数字作为无穷大

    for(int i = 0 ; i < n ; i ++) d[i][i] = 0;

    // 然后做一遍f
    for(int k = 0 ; k < n ; k ++)
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < n ; j ++)
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    // 然后求出了任意两点之间的最短距离

    double ans1 = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            if(d[i][j] < 1e20)
                maxd[i] = max(maxd[i], d[i][j]);
            ans1 = max(maxd[i], ans1);
        }// 答案可能就是这个直径
    }
    double ans2 = 1e20;
    // 然后得到每一个点到另一个点的最大距离
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            if(d[i][j] > 1e20 / 2)
            {
                ans2 = min(get_dis(a[i], a[j]) + maxd[i] + maxd[j], ans2);
                // 只有等于0, 我们才连起来
            }
        }
    }
    // 然后对于每一个不连通的点, 我们求出一个一个距离, 然后我们要
    printf("%.6lf\n", max(ans1, ans2));


    return 0;
}