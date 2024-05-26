#include <iostream>
#include <vector>
#include <math.h>
#include <string>

#define int long long

using namespace std;
const int N = 2000010;
int mod = 1e9 + 7;

int sum[N];// sum[i]表示前i组的和
// sum[i] = sum[i - 1] + i;

int find(int x)
{
    int l = 1, r = 2000000;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (mid * (mid + 1) <= x * 2)
        {
            l = mid;
        }
        else
            r = mid - 1;
    }
    return l;
}

signed main()
{
    int tmp = 0;    
    for(int i = 1; i <= 2000000 ; i ++)
    {
        tmp += i;// sum[i]表示前i个区间的元素之和, tmp等于当前数组的元素之和
        sum[i] = sum[i-1] + tmp;
    }
    int n;cin >> n;
    while (n--)
    {
        int L, R;
        cin >> L >> R;
        // 计算l和r是在第几个区间,
        int n1 = find(L - 1), n2 = find(R);
        // 得到L和R前面的那个区间, 然后用L减掉前面所有区间的个数, 就得到了L在这个区间中的位置, 也就可以得到L之前的和了
        // 然后算出L和R在这个区间的那个位置
        // cout << "n1 : " << n1 << " n2 : " << n2 << endl;
        int lx = (L - 1) - (n1 + 1) * n1 / 2;
        int rx = R - (n2 + 1) * n2 / 2;
        // 有可能是是0, 那么这个区间就是0
        // cout << "lx : " << lx << " rx : " << rx << endl;
        int suml = 0, sumr = 0;
        if(lx == 0) 
        {
            suml = sum[n1];
        }
        else if(lx < 0) suml = 0;
        else suml = sum[n1] + (lx + 1) * lx / 2;
        if(rx == 0)
        {
            sumr = sum[n2];
        }
        else sumr = sum[n2] + (rx + 1) * rx / 2;
        // cout << "suml : " << suml << " sumr : " << sumr << endl;
        cout << sumr - suml << endl;
    }
    return 0;
}
