#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
const int N = 100010;
int f[N];
signed main()
{
    string a; cin >> a;
    a = '#' + a;
    f[1] = 1, f[2] = 2;
    for(int i = 3 ; i <= 100000 ; i ++)
        f[i] = (f[i-1] + f[i-2]) % mod;

    int ans = 1;
    for(int i = 1; i + 1 <= a.size() ;)
    {  
        if(a[i] == 'm' || a[i] == 'w')
        {
            puts("0");
            return 0;
        }
        if(a[i] == a[i + 1] && (a[i] == 'u' || a[i] == 'n'))
        {
            // 找到一个u串
            for(int j = i + 1 ; j + 1 <= a.size() ; j ++)
            {
                if(a[j] != a[j + 1])
                {
                    // 如果这个数和下一个数不相等了，因为已经确定这个数是一个u了，所以这个就是在最后一个u
                    ans = (ans * (f[j - i + 1])) % mod;
                    // cout << "i : " << i << " j : " << j << endl;
                    i = j + 1;
                    break;
                }
            }
        }
        else i ++;
        // if(a[i] == a[i + 1] && a[i] == 'n')
        // {
        //     // 找到一个u串
        //     for(int j = i + 1 ; j + 1 <= a.size() - 1 ; j ++)
        //     {
        //         if(a[j] != a[j + 1])
        //         {
        //             ans = (ans * (f[j - i + 1])) % mod;
        //             cout << "i : " << i << " j : " << j << endl;
        //             i = j + 1;
        //             // 如果这个数和下一个数不相等了，因为已经确定这个数是一个u了，所以这个就是在最后一个u
        //             break;
        //         }
        //     }
        // }
    }
    cout << ans << endl;
    return 0;
}
