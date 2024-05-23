#include <iostream>
#include <set>

using namespace std;
typedef pair<long double,long double> pii;// 存点的下标
typedef unsigned long long ll;

const int N = 3010;// f[i][j]表示时间是i, 体力剩余j的情况, 这样子体力的差值就是+1, 时间就是-1
// 位移就是(m - j - i)
// m - j就是i的时间, 就是走了2 * i步, i - (m - j)得到的就是实际位移

int f[N][N];
int mod  = 1000000007;
int main()
{
    int d, t, m;
    cin >> d >> t >> m;

    f[0][m] = 1;
    for(int i = 1 ; i <= t; i ++)
    {
        for(int j = 0 ; j <= m ; j ++)
        {// 向上游实际上是0, 所以就是计算有多少, 因为向上游的时候也有向下游
            if((i - 2 *(m - j)) < d && i >= (m - j))
                f[i][j] += (f[i-1][j] + f[i - 1][j + 1]) % mod;
        }
    }

    cout << f[t][0] << endl;

    return 0;
}