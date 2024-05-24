#include <iostream>
#define int long long

using namespace std;
typedef long long ll;

int n;
ll C(int a, int b)
{
    ll res = 1;
    // 求出的是公式就是n * (n-1) * (n-2) * ... * (n-b+1) / (1 * 2 * 3 * ... * b)
    // 所以分出来一个是从n开始一个是从1开始
    for(int i = a, j = 1; i >= a - b + 1; i --, j++)// 
    {
        res = res * i / j;
        if(res > n)
            return res;
    }
    return res;
}


signed main()
{
    cin >> n;
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 16; i >= 0 ; i --)
    {
        int l =  i * 2, r = 2e9;// 二分枚举这个斜列 
        while(l < r)
        {
            ll mid = l + r >> 1;
            ll val = C(mid, i); // 如果相等的话, 这个时候mid就是就是行数, 这个下标是从(0, 1, 2, ..., mid)
            if(val == n)
            {// 找到了斜列数i, 行数i * 2 + 1, 然后上面就有2 * i行, 所以等差数列求出上面的数字, 然后加上斜列数 + 1, 因为斜列数从0开始
                cout << (mid + 1) * mid / 2 + i + 1  << endl;
                return 0;
            }
            else if(val < n)
            {
                l = mid + 1;// 那么
            }
            else 
            {
                r = mid;
            }

        }
    }

    return 0;
}