#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;

void solve()
{
    int l, r, L, R;cin >> l >> r >> L >> R;
    // 区间可以重叠, 重叠的部分是一定要锁起来的
    // 选一个小的区间
    if(R > r)
    {
        swap(r, R);
        swap(l, L);
    }
    else if(R == r)
    {
        if(L > l)// 让l更小
        {
            swap(r, R);
            swap(l, L);
        }
    }
    // cout << l << " " << r << "\n";
    // cout << L << " " << R << "\n";
    
    map<int, int> mp;
    for(int i= l; i <= r ; i ++)
    {
        mp[i]++;
    }
    int ans = 0;

    for(int i= L; i <= R; i ++)
    {
        // cout << i << " " << mp[i + 1] << "\n";
        // if(mp[i + 1] != 0)
        // {
        //     // 如果两个同时存在
        //     ans ++;
        // }
        mp[i]++;
    }
    int rr = max(r, R);
    for(int i = min(l, L) ; i < rr; i ++)
    {
        if(mp[i] == 2)
        {
            ans ++;
        }
    }
    if(l == L)
    {
        cout << ans << "\n";
        return;
    }
    cout << ans + 1 << "\n";
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}