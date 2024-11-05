#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 510;
// int pre3[N], pre4[N];
int n;

void solve()
{
    int k; cin >> n >> k;
    string s; cin >> s;
    s = ' ' + s;
    int ca = 0, cb = 0;
    int A[N] = {0}, B[N] = {0};
    int pre1[N] = {0}, pre2[N] = {0};
    // for(int i = 0 ; i <= n + 1 ; i ++)
    // {
    //     pre1[i] = pre2[i] = 0;
    // }   
    for(int i = 1 ; i <= n ; i ++)
    {
        if(s[i] == 'A')
        {
            A[i] = 1;
            ca ++;
        }
        else {
            B[i] = 1;
            cb ++;
        }
    }
    int p1 = cb - k;
    int ans = 0;
    // cout << ca << " " << cb << "\n";
    if(k == cb)
    {
        cout << "0\n";
        return;
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        pre1[i] = pre1[i - 1] + A[i];
        pre2[i] = pre2[i - 1] + B[i];
        // if(pre1[i] == p1)
        // {
        //     // 如果前面有了
        //     ans = i;
        //     break;
        // }
        // cout << pre1[i] << " " << pre2[i] << "\n";
    }
    if(cb > k){
        // cout << "p1 : " << p1 << "\n";
        for(int i = 1 ; i <= n ; i ++)
        {
            // cout << pre2[i] << " ";
            if(pre2[i] == p1)
            {
                // 如果前面有了
                ans = i;
                break;
            }
            // cout << pre1[i] << " " << pre2[i] << "\n";
        }
        // cout << "\n";
        // for(int i = n ; i >= 1 ; i --)
        // {
        //     pre3[i] = pre3[i + 1] + A[i];
        //     pre4[i] = pre4[i + 1] + B[i];
        //     if(pre3[i] == k)
        //     {
        //         // 如果后面有了k个
        //         ans = min(ans, i);
        //         break;  
        //     }
        //     // cout << pre3[i] << " " << pre4[i] << "\n";
        // }
        cout << 1 << "\n";
        if(ans != 0)
        {
            cout << ans << " A\n";
        }
        else  cout << n << " A\n";
    }
    else 
    {
        // 如果少了的话
        // cout << k - cb << "\n";
        for(int i = 1 ; i <= n ; i ++)
        {
            // cout << pre1[i] << " ";
            if(pre1[i] == k - cb)
            {
                cout << "1\n";
                cout << i << " B\n";
                return;
            }
        }

    }
    // cout << "\n";
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