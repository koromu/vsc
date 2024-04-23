#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(a, b % a);
}
int main()
{
    // cout << gcd(10001, 20002) << endl;
    //问的就是一个x使得x / k 小于n
    int n, k;
    cin >> n >> k;
    //这个k一定要有, 所以找到一个x使得k * x <= n, (x + 1) * k > n
    //所以是要找符合k * x <= n的最大的x, 也就是区间的右边界
    long long  l = 1 , r = n;
    while(l < r)
    {
        long long mid = l + r + 1 >> 1;
        if(mid * k > n)//如果合法, 那么可以是这扩大mid
            r = mid - 1;
        else l = mid;
        // std::cout << " l : " << l << " r : " << r << endl;
    }
    cout << r << endl;
    // if((l + 1) * k <= n) cout << l + 1 << endl;
    // else  cout << l << endl;
    // while(l < r)
    // {
    //     int mid = l + r >> 1;
    //     //枚举k的个数, 如果小于k, 那么就扩大
    //     if(check(mid))
    //     {

    //     }
    // }
    // std::cout << r << endl;


    // cout << n / k << endl;//神仙代码
    return 0;
}
