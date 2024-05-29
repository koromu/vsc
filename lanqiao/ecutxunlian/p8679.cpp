#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <math.h>
#include <queue>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 200010, M = 1010;

void solvea()
{
    int a = -1, b = -1, c = -1, d = -1, e = -1;
    for(int i = 1 ; i <= 20 ; i ++)
    {
        int no, t1, t2, t3, t4, t5;cin >> no >> t1 >> t2 >> t3 >> t4 >> t5;
        a = max(a, t1), b = max(b, t2), c = max(c, t3), d = max(d, t4), e = max(e, t5);
    }
    cout << a + b + c + d + e << endl;
}

void solveb()
{
    vector<int> v1;
    int n = 2019;
    while(n)
    {
        int a = n % 26;
        v1.push_back(a);
        n/=26;
    }
    // 数组中最高位是高位, 最低位是地位
    for(int i = v1.size() - 1 ; i >= 0 ; i --)
    {
        cout << (char)(v1[i] + 'A');
    }
    cout << endl;
}

void solvec()
{
    int sum[20200000] = {1, 1, 1, 3, 5, 9, 17};
    for(int i = 4 ; i <= 20190500 ; i ++)
    {
        sum[i] += (sum[i - 1] + sum[i - 2] + sum[i - 3]);
    }// 第四项以后的每一项都可以由前面的三项递推而来
    cout << sum[20190324] << endl;
}

signed main()	
{
    solvec();    

    return 0;
}