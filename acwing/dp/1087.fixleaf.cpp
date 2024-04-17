#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int n , k;
const int N = 100010;

ll w[N], q[N];
ll f[N];

ll g(int x)
{
    return f[x - 1] - w[x];
}
int main()

{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++) 
    {
        cin >> w[i];
        w[i] += w[i-1];
    }

    int hh = 0, tt = 0;
    for(int i = 1; i <= n ; i ++)
    {//在更新答案, 之前, 把队列控制在长度k之内
        if(hh <= tt && i - q[hh]  >= k + 1) hh ++;//这个区间可以存到i - j的最小值, 需要维护的最小值
        f[i] = max(f[i-1], g(q[hh]) + w[i]);//取出队头元素
        while(hh <= tt && g(i) >= g(q[tt])) tt--;//要维护的东西错了, 不只是s[i-j], 还有f[i-j-1], 维护这个的最大值, 所以是队头最大
        q[++tt] = i;
    }

    cout << f[n] << endl;
    return 0;
}//枚举