#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;

void solve()
{   
    int n, m; cin >> n >> m;
    // 非常巧妙的构造呀
    // 对于原数n, 我们要变成1 ~ m倍
    // 使得最后面的0个数最多, 相同0的情况下, 然后这个数还要经可能的大
    // 可以发现一个数能有的0的个数就是10的个数, 所以把一个数由经可能多的10组成
    // 我们现在要构造一个数x, x的范围是[1, m]
    // 然后凑10的话就是2 * 5
    // 所以我们可以在n中找到2和5的个数
    // 然后先把5凑成10, 也就是让x从1开始乘2, 这样就经可能多的凑出了10
    // 然后再看n还有多少个2, 然后让x乘5, 这样就会接近m, 如果超过了m那么就退掉了一个就行了
    // 这样的话可能还会有一个C1存在, 或者一些2和一些5
    // 我们尽可能的把没有凑成10的2和5凑成10就行了
    // 最后我们还要看如果是n中的2和5先用完, 如果x还能直接扩大10的话, 那也可以直接算出还能加多少个0, 也就是还能除以几个10
    // 但是这样的可能只是合法的, 还不是最大的, 所以可以下取整算出还能扩大多少倍
    int c2 = 0, c5 = 0; 
    int rn = n , rm = m;
    while(n % 2 == 0)
    {
        // 如果还是2的倍数的话, 就继续除以2
        c2++;
        n /= 2;
    }
    while(n % 5 == 0)
    {
        c5++;
        n /= 5;
    }
    // 算出来c2和c5
    // if(rn % 10 == 0&& c2 && m <= 10 )
    // {
    //     int tmp = rn;
    //     while(rn % 10 == 0)
    //     {
    //         rn /= 10;
    //     }
    //     if(rn * m < 10)
    //     {
    //         cout << tmp * m << endl;
    //         return;
    //     }
    //     else rn = tmp; 
    // }
    // cout << "c2 : " << c2 << " c5: " << c5 << endl;
    int x = 1;
    // 凑2
    while(c5 > c2 && m / 2) 
    {
        x *= 2;
        m /= 2;
        c5--;
    }
    while(c2 > c5 && m / 5)
    {
        x *= 5;
        m /= 5;
        c2--;
    }// 这样间接地产生更多的10
    // cout << "m :" << m << endl;
    // cout << "x :" << x << endl;
    while(m / 10)
    {
        x *= 10;
        m /= 10;
    }// 这样直接地产生更多的10
    // cout << "n: " << n << " rm : " << rm << endl;
    // cout << "x : " << x << endl;
    cout << rm / x * x * rn  << endl;
}


signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
