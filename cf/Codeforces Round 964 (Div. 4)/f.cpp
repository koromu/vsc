#include <bits/stdc++.h>
using namespace std;
#define int long long

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int pre[N];
int jc[N], injc[N];

int qmi(int a, int b, int p)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % P;
}

int n, k; 
void init()
{
    // 预处理阶乘数组和逆元数组
    jc[0] = 1;
    injc[0] = 1;
    for(int i = 1 ; i <= N - 5 ; i ++)
    {
        jc[i] = jc[i - 1] * i % P;
        injc[i] = qmi(jc[i], P - 2, P);
    }
    // cout << "jc: " << jc[n] << "\n";
}

int C(int n, int m)
{
    if(m > n) return 0;
    return jc[n] * injc[m] % P * injc[n - m] % P;
}

void solve()
{
    cin >> n >> k;
    int c0 = 0;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> w[i];
        pre[i] = pre[i - 1] + w[i];
        // cout << pre[i] << " ";
        if(w[i] == 0) c0++;
    }
    // cout << "\n";
    // 
    int ans = 0;
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     if(w[i] == 1)
    //     {
    //         cout << pre[n] - pre[i] << "\n";
    //     }
    //     int cc = 
    //     ans = (ans +  ) % P;// 加上从(n - i) - ((k + 1) / 2 - 1) 选 
    //     // 从这个区间中1的个数中选((k + 1) / 2  - 1) * (n - i) - ((k + 1) / 2 - 1) 选(k - (k + 1) / 2)个
    // }

    // 如果

    if(pre[n] < (k + 1) / 2)
    {
        cout << "0\n";
        return;
    }
    // cout << pre[n] << " " <<   C(2, 2) << "\n";
    // cout << jc[2] << " " << injc[2] << " " << injc[0] << "\n";
    // cout << C(pre[n], 2) << " " << C(c0, (k - 2)) << "\n";
    for(int i = (k + 1) / 2 ; i <= k ; i ++)
    {
        if(pre[n] < i) break;
        ans = (ans + C(pre[n], i) * C(c0, (k - i)) % P) % P;// 选一半以上的1和剩余的0
    }
    cout << ans << "\n";
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    init();
    while(t--)
        solve();

return 0;
}