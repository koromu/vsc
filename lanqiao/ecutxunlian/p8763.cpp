#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <bitset>
#define int long long

using namespace std;
const int N = 10010;
signed main()
{
    int n, t;
    cin >> n >> t;
    string tmp; cin >> tmp;
    bitset<N> b1(tmp), b2;
    b2 = b1;
    // 然后转换b2判断多少次以后可以变成b1
    int tmod = 0;
    while(b1 != b2 || !tmod)
    {
        b2 ^= (b2 >> 1);
        tmod++; 
    }

    t %= tmod;
    while(t--)
    {
        b1 ^= (b1 >> 1);
    }
    for(int i = n - 1 ; i >= 0 ; i --) cout << b1[i];
}