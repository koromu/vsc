#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 100010;
using namespace std;

typedef long long ll;
ll n, k, q;
double a[N], b[N];

void solve()
{
    cin >> n >> k >> q;
    // a是距离, b是时间
    for(int i = 1 ; i <= k ; i ++ ) cin >> a[i];
    for(int i = 1 ; i <= k ; i ++ ) cin >> b[i];

    while(q--)
    {
        ll d;
        cin >> d;
        int l = 0 , r = k;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(a[mid] <= d)
            {
                l = mid;
            }
            else r = mid - 1; 
        }

        if(l == k)
            cout << (ll)b[l] << " " ;
        else 
        {
            // 计算一下
            // cout << "    b[l] : " << b[l] << " b[l + 1] : " << b[l + 1] << " a[l] : " << a[l] << " a[l + 1] : " << a[l + 1] << " d : " << d << endl;//使用cout方法查看数据
            ll ans = 0;
            ans += b[l] + (ll)((b[l + 1] - b[l]) * (d  - a[l])  / (a[l + 1] - a[l])  );
            printf("%lld ", ans);
        }
    }
    cout << endl;

}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}