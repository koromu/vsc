#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#define long long int
using namespace std;
// typedef long long ll;

// int gcd(int a, int b)
// {
//     if(b == 0)
//         return a;
//     return gcd(b, a % b);
// }
const int N = 1010;

struct light{
    double t, x;
    bool operator < (light &r)
    {
        return t < r.t;// <号比较的是, 左边的t小于右边的t
    }
}ls[N];

int n, l;
void solve()
{
    cin >> n >> l;
    for(int i = 0 ; i < n ; i ++) {
        cin >> ls[i].t;
        ls[i].x = i;
    }// 存下下标和编号
    double ans = 0;// 算出最大的间隙是多少, 然后除以2得到的就是这个最大的最小间隙
    sort(ls, ls + n);

    for(int i = 0 ; i + 1 < n ; i ++)
    {
        ans = max(ls[i + 1].t - ls[i].t, ans);// 位移差
    }
    // 第一个和最后一个灯需要照到路的两端
    ans /= 2;
    ans = max(max(ls[0].t, ans), l - ls[n - 1].t);
    printf("%.10lf", ans);
}


int main()
{
    int _;
    _ = 1;
    while(_--)
    {
        solve();
    }
    return 0;
}
