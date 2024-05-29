#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <math.h>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 200010, mod = 1e9 + 7;

int w[N], h[N], bit[N], ans[N];

signed main()	
{
    int X;cin >> X;
    int n; cin >> n;
    for(int i = n - 1 ; i >= 0 ; i --) {
        cin >> w[i];
        bit[i] = max(w[i] + 1, (int)2);
    }

    int m; cin >> m;
    for(int i = m - 1  ; i >= 0 ; i --) {
        cin >> h[i];
        bit[i] = max(h[i] + 1, bit[i]);
    }   


    // for(int i = n - 1 ; i >= 0 ; i --) 
    //     cout << bit[i] << " " << w[i] << " " << h[i] << endl;

    // 这里又学到了一中进制的理解
    // (100010)二进制转换成10进制一般是 1 * 2^5 + 1 * 2^1 = 33
    // 如果看成 1 * 2^0 + 1 * 2 * 2 * 2 * 2 * 2, 也就是当前位的系数, 乘以前面每一位的进制, 第一位前面没有, 就当作乘1
    // 这样就可以计算出这个X进制的值了 
    
    int a = 0, b = 0;

    // int maxv = max(m, n);
    // cout << "maxv : " << maxv << endl;
    // for(int i = maxv - 1 ; i >= 0 ; i -- )// 枚举每一个位置
    // {
    //     // 记录前面有多少进制
    //     a += w[i] * bits;
    //     b += h[i] * bits;
    //     bits *= bit[i];
    //     // cout << bits << " " << a << " " << b << endl;
    // }// 通过位数不同的计算, 发现, 这个a和b需要分开来算
    // for(int i = n - 1 ; i >= 0 ; i --) 
    //     cout << "bit[" << i << "] :  " << bit[i]<< endl;
    
    int bits = 1;
    for(int i = 0; i < n ; i ++ )// 枚举每一个位置
    {
        // 记录前面有多少进制
        a += (w[i] * bits) % mod;
        bits = bits * bit[i] % mod;
        // cout << bits << " " << a << " " << b << endl;
    }// 通过位数不同的计算, 发现, 这个a和b需要分开来算

    bits = 1;
    for(int i = 0 ; i < m ; i ++ )// 枚举每一个位置
    {
        // 记录前面有多少进制
        b += h[i] * bits % mod;
        bits = bits * bit[i] % mod;
        // cout << bits << " " << a << " " << b << endl;
    }// 通过位数不同的计算, 发现, 这个a和b需要分开来算
    // cout << "a : " << a << " b : " << b << endl;
    cout << ((a - b) % mod + mod) % mod << endl;
    
    return 0;
}
