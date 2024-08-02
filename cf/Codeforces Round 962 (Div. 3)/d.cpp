#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

int n, x;
bool check(int a, int b, int c)
{
    if(a * b + b * c + c * a <= x)
        return true;
    else return false;
}
void solve() {
    cin >> n >> x;
    int count = 0;

    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1; (i * j) < n ; j ++)
        {
            // int l = j + 1, r = n;
            // while(l <= r)
            // {
            //     int mid = (l + r + 1) >> 1;
            //     if(check(i, j, mid))
            //         l = mid;
            //     else
            //         r = mid - 1;
            // }
            // count += l;
            count += max(min(x - i - j, (n - i * j ) / (i + j)), 0ll);
        }
    }
    cout << count << endl;
    // count *= 6;
    // int tmp = 0;
    // for(int i = 1 ;  2 * i <= n ; i ++)
    // {
    //     int l = i + 1, r = n;
    //     while(l <= r)
    //     {
    //         int mid = (l + r + 1) >> 1;
    //         if(check(i, mid, mid))
    //             l = mid;
    //         else
    //             r = mid - 1;
    //     }
    //     tmp += l;
    // }
    // count += (3 * tmp);
    // int l = 1, r = n;
    // while(l <= r)
    // {
    //     int mid = (l + r + 1) >> 1;
    //     if(check(mid, mid, mid))
    //         l = mid;
    //     else
    //         r = mid - 1;
    // }
    // count += l;

    // cout << count << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
