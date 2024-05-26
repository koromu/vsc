#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#define int long long

using namespace std;
const int N = 70;
int C(int x, int y)// 从x个中选y个的组合数
{
    int ans = 1;
    for(int i = x, j = 1; i >= x - y + 1; i --, j ++)
    {
        ans = ans * i / j;
    }
    return ans;
}

int dp[N][N];// 当前是第i位, 前面有j个1的合法方案数量

signed main()
{
    int n, k;
    cin >> n >> k;
    int last = 0;// 前面有多少个1
    int ans = 0;
    for(int i = 63 ; i >= 0 ; i --)
    {
        if(n >> i & 1)
        {// 如果取出这一位是1的话
            ans += C(i, k - last);// 如果这一位写0的话, 那么直接加上(从剩余i位选k - last位)
            last ++; //
            if(last > k) break;
        }
        if(!i && last == k) ans++;
        
    }

    cout << ans << endl;
    return 0;
}