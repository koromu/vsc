#include <iostream>
#include <algorithm>
#include <queue>

#define int long long
using namespace std;

const int N = 100010;

typedef pair<int, int> pii;

signed main()
{
    // 贪心的想, 一个长度为m, 个位数字之和为s的数字

    // 其中最小的数, 因为不能有前导0
    // 从最低位开始看, 最低位尽量把数填完, 然后最高位填1, 填完最低位开始填次低位, 最后只要留一个1就行了
    // 所以先看看最高位后面有几个位置, 试试全填9能不能用完, 能用完的话, 先-1给最高位留一个
    // 然后mod 9 试试还剩x
    // 然后 /9 算出能填y个9, 所以最后是 "y" 个9, "1" 个x, 然后 "长度 - y - 2" 个 0

    // 最大值的话从前往后直接填9, 然后填x, 最后补0 就行了
    int n, m; cin >> n >> m;
    int x, y, z;
    vector<int> maxv, minv;
    // 最大值的话是先填9, 然后填x, 最后补0
    // 最小值的话是先填1, 再填0, 再填先, 最后补9
    
    if(n == 1 && m == 0)
    {
        puts("0 0");
        return 0;
    }
    if(m == 0) 
    {
        puts("-1 -1");
        return 0;
    }

    if((n - 1) * 9 >= m)
    {
        x = m % 9;
        y = m / 9;
        z = n - y - 1;
        for(int i = 0 ; i < y ; i ++) maxv.push_back(9);
        maxv.push_back(x);
        for(int i = 0 ; i < z ; i ++) maxv.push_back(0);

        x = (m - 1) % 9;// 如果这是个0
        y = (m - 1) / 9;
        z = n - y - 2;
        // cout << "x : " << x << " y : " << y << " z : " << z << endl;
        minv.push_back(1);
        for(int i = 0 ; i < z ; i ++) minv.push_back(0);
        minv.push_back(x);
        for(int i = 0 ; i < y ; i ++) minv.push_back(9);
    }
    else if((n - 1) * 9 < m && n * 9 >= m)
    {
        y = n - 1;
        x = m - (n - 1) * 9;
        // cout << "x : " << x << " y : " << y << " z : " << z << endl;
        minv.push_back(x);
        for(int i = 0 ; i < y ; i ++)minv.push_back(9);

        for(int i = 0 ; i < y ; i ++) maxv.push_back(9);
        maxv.push_back(x);
    }
    else 
    {
        puts("-1 -1");
        return 0;
    }

    for(int i = 0 ; i < n ; i ++) cout << minv[i];
    cout << " ";
    for(int i = 0 ; i < n ; i ++) cout << maxv[i];

    return 0;
}

