#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;

int w[N];

signed main()
{
    int n; cin >> n;
    string a ;cin >> a;
    a += '#';
    // 处理字符串
    // 如果是1那么就看后背一个1是不是0
    for(int i = 1 ; i <= a.size() - 1; i ++)
    {
        if(a[i - 1] == '1')
        {
            if(a[i] == '0')
            w[i++]++;
        }// 否则不管
    }
    // 得到了前缀和一个数组，然后求一边前缀和
    for(int i = 1; i <= a.size() - 1; i ++ )
    {
        w[i] += w[i - 1];
        // cout << w[i] << " ";
    }
    int k; cin >> k;
    for(int i = 0 ; i < k ; i ++)
    {
        int l, r; cin >> l >> r;
        cout << w[r - 1] - w[l - 1] << endl;
    }

    return 0;
}
