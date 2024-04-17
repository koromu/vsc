#include <iostream>
#include <climits>
using namespace std;

const int N = 200010;
int w[N];//存代价
int f[N];//f[i]表示, 当前选第i个烽火台的合法情况下, 最小代价
int q[N];
int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n ; i ++) cin >> w[i];

    int hh = 0, tt = 0;
    for(int i = 1 ; i <= n ; i ++)//枚举右端点
    {
        if(hh <= tt && i - q[hh] >= m + 1) hh++;//看下区间长度
        f[i] = f[q[hh]] + w[i];//加上前面这个区间的最小代价
        while(hh <= tt && f[q[tt]] >= f[i]) tt--;
        q[++tt] = i;
    }

    int ans = INT_MAX;
    for(int i = n ; i >= n - m + 1 ; i --) //因为另一坐城市的左边m个区间至少要有一个烽火台, 所以从第n个烽火台开始往前m个中的合法做法中的最小值
        ans = min(ans, f[i]);
    cout << ans << endl;
    return 0;
}