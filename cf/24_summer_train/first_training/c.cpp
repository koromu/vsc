#include <iostream>
#include <algorithm>
#include <math.h>

#define int long long
using namespace std;

const int N = 55;

void solve()
{   
    int l, r, x, a ,b;
    cin >> l >> r >> x >> a >> b;
    if(a == b) 
    {
        puts("0");
        return;
    }
    if((a - l < x && r - a < x) || (b - l < x && r - b < x) || r - l < x)
    {
        // cout << "第0个" <<  endl;
        puts("-1");
        return;
    }
    // 先把不能到的情况判断一下

    if(abs(a - b) >= x) 
    {
        // cout << "第1个" << endl;
        puts("1");
        return;
    }
    else
    {
        // 不能一步到呀
        if(b - l >= r - b)
        {
            // 如果l比r到b远或者相等
            if(a - l >= x)
            {
                // cout << "第2个" << endl;
                // 如果去的了l, 因为l是离b最远的
                puts("2");
                return;
            }
            else
            {// 那只能去r了，r的话还要看啊可能和b的情况
                // cout << "第3个" << endl;
                if(r - b >= x) puts("2");
                else puts("3");
            }
        }
        else
        {// r到b远
            if(r - a >= x)
            {
                // cout << "第4个" << endl;
                puts("2");
                return;
            }
            else
            {
                // cout << "第5个" << endl;
                if(b - l >= x) puts("2");
                else puts("3");
            }
        }
    }
    return;
}


signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
