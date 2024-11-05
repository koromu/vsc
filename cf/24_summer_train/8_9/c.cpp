#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;
// int pre1[N], pre2[N];
void solve()
{
    int n ; cin >> n;
    // int p1 = 0, p2 = 0, maxz = 0, maxf = 0, k = 0, last = 0;
    int ans = -1e18, k = 0;
    
    int ll = 0;
    for(int i = 1 ; i <= n; i ++) 
    {
        cin >> w[i];
        if(ll == 0) ll = w[i];
        else if(ll * w[i] < 0)
        {
            k ++;
            ll = w[i];
        }
    }
    // 如果是交替的必选，如果是连续的选最小的

    int tmp = w[1];
    int last = 0;
    for(int i = 1, kk = 0; i + 1 <= n ;)
    {
        last = w[i];
        for(int j = i + 1; j <= n ; j ++)
        {
            int now = w[j];
            // cout << "now :" << now << "\n";
            if(last * now < 0)
            {
                // 说明交替必选
                tmp += now;
                i = j;
                kk++;     
                break;
            }
            else 
            {
                // 说明同号，在同号之中找到一个最大的正数，最小的负数
                if(now > 0)
                {
                    if(now > last)// 正数的话要大的
                    {
                        tmp += (now - last);
                        last = now;
                        // cout << "now : " << now << " last : " << last << "\n";
                        // cout << "tmp : " << tmp << "\n";
                    }
                    // 否则不变
                }
                else if(now < 0)
                {
                    // 如果是负数
                    if(now > last)// 负数的话要大的
                    {
                        tmp += (now - last);
                        last = now;
                        // cout << "now : " << now << " last : " << last << "\n";
                        // cout << "tmp : " << tmp << "\n";
                    }
                    // 否则不变
                }
                i++;
            }
        }
        // cout << kk << " " << k << "\n";
        // if(kk == k) ans = max(ans, tmp);
        // cout << tmp << "\n";
    }
    // cout << last << "\n";
    if(last * w[n] < 0)
    {
        // 说明交替必选
        ans += w[n];
    }
    else if(w[n] * last > 0)
    {    
        if(w[n] > 0)
        {
            if(w[n] > last)// 正数的话要大的
            {
                tmp += (w[n] - last);
            }
            // 否则不变
        }
        else if(w[n] < 0)
        {
            // 如果是负数
            if(w[n] > last)// 负数的话要大的
            {
                tmp += (w[n] - last);
            }
            // 否则不变
        }
    }
    ans = max(ans, tmp);
    // cout << last << "\n";
    cout << ans << "\n";
    // dp[i][j][1] 当前是第i个，选了j个，当前这个不选的最大值


    // for(int i = 1 ; i <= n; i ++) 
    // {
    //     cin >> w[i];
    //     if(last == 0) last = w[i];
    //     pre1[i] = pre1[i - 1] + (w[i] >= 1);
    //     pre2[i] = pre2[i - 1] + (w[i] < 0);
    //     if(last * w[i] < 0)
    //     {
    //         last = w[i];
    //         k ++;
    //     }
    // }// 不一定

    // for(int i = 1; i <= n; i ++)
    // {
    //     cout << "长度 : " << min(pre1[n] - pre1[i - 1], pre2[n] - pre2[i - 1]) << "\n";
    //     if(min(pre1[n] - pre1[i - 1], pre2[n] - pre2[i - 1]) < k) break;// 小于长度了
    //     if(maxz == 0)
    //     {
    //         maxz = w[i];
    //         p1 = p2 = i;
    //         maxf = w[i];
    //     }
    //     if(w[i] > maxz && w[i])
    //     {
    //         p1 = i;
    //         maxz = w[i];
    //     }
    //     if(w[i] < maxf && w[i] < 0)
    //     {
    //         maxf = w[i];;
    //         p2 = i;
    //     }
    // }

    // cout << p1 << " " << p2 << endl;

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