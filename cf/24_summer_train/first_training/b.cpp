#include <iostream>
#include <algorithm>

#define int long long
using namespace std;

const int N = 55;
int b[N];
int a[N];// 前缀和数组

void init()
{
    for(int i = 1 ; i <= N ; i ++)
    {
        a[i] = (a[i-1] + i);
        // cout << "i : " << i << " : " << a[i] << endl;
    }
}

void solve()
{   
    // 先准备一个前缀和

    // 我们先把已经有的数给排好序，然后算出这个数变成排列需要加的数S1
    // 和S进行比较，如果大于S，那么就不用算了
    // 否则进行下一步
    // 利用前缀和算出S-S1是不是可以由后面的一串和组成,如果可以，则是YES，不可以就是NO
    int m, s; cin >> m >> s;
    
    for(int i = 1 ; i <= m  ; i ++) cin >> b[i];
    sort(b + 1, b + m + 1);
    // 遍历b数组
    int s1 = 0;
    for(int i = 1 ; i <= m ; i ++)
    {
        if(b[i] != (b[i-1] + 1))
        {
            // 如果b不是连续的, 那么开始计算s1
            // 要加上这两个数之间的片段
            // 比如是5和10
            // 中间少了：6 7 8 9 
            // 也就是要加上a[9] - a[5]，也就是a[b[i] - 1] - a[b[i - 1]]
            // 比如是11 和 13
            // a[12] - a[11]
            s1 += (a[b[i] - 1] - a[b[i - 1]]);
        }
    }
    // 把已经有的b处理好之后
    if(s1 > s)// 如果已经大于了，那么就直接超过了，不用算了
    {
        puts("NO");
        return;
    }
    // 我们要从b的最后一个数+1开始加，因为数据不大，直接暴力
    // 如果大的话可能要试试二分
    int now = b[m] + 1;
    while(s1 < s)
    {
        // cout << now << " ";
        s1 += (now++);
    }
    // cout << endl;
    // 出来之后要么大于，要么等于
    if(s1 == s) puts("YES");
    else puts("NO");
    return;
}


signed main()
{
    init();
    int _; cin >> _;
    while(_--) solve();
    return 0;
}