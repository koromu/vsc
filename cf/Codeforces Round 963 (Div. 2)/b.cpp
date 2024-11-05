#include <bits/stdc++.h>
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

int w[N];

// void solve()
// {
//     // 找到一个奇数和, 然后替换一个较小的, 所以枚举偶数, 然后在后面找到一个奇数
//     int n; cin >> n;
//     int co = 0, cj = 0;
//     int maxj = 0, maxo = 0, maxv = 0;
//     int pos = 0;
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         cin >> w[i];
//         if(w[i] % 2 == 0) co++;
//         else cj++;
//         maxo = max(maxo, w[i]);
        
//         if(w[i] > maxj && w[i] % 2 == 1)
//         {
//             pos = i;
//             maxj = max(w[i], maxj);
//         }
//     }

//     if(!co || !cj)
//     {
//         cout << "0\n";
//         return;
//     }

//     if(maxj > maxo) {
//         cout << co << "\n";
//         return;
//     }
//     int ans = 0;
//     int tmp = co;
//     bool f = false;
//     // cout << "pos : " << pos << "\n";
//     for(int i = pos - 1 ; i >= 1 ; i --)
//     {
//         if(w[i] % 2 == 0 && w[i] < maxj)
//         {
//             maxj += w[i];
//             w[i] += maxj;
//             ans ++;
//             co--;
//             if(maxj > maxo)
//             {
//                 ans += co;
//                 f = true;
//                 break;
//             }
//         }
//     }
//     co = tmp;
//     int tmp1 = 0;
//     for(int i = pos + 1 ; i <= n ; i ++)
//     {
//         if(w[i] % 2 == 0 && w[i] < maxj)
//         {
//             maxj += w[i];
//             w[i] += maxj;
//             tmp1 ++;
//             co--;
//             if(maxj > maxo)
//             {
//                 ans = min(ans, tmp1 + co);
//                 f = true;
//                 break;
//             }
//             // cout << "maxj : " << maxj << "\n";
//         }
//     }
//     if(!f) cout << tmp + 1 << "\n";
//     else{
//         if(ans == 0) cout << tmp1 + co + 1 << "\n";
//         else cout << ans << "\n";
//     }
//     // cout << pos << "\n";
//     // cout << co << " " << cj << "\n";
//     // 对于最大的奇数在左右找小于它的欧数, 如果更新出了大于最大值偶数的奇数
//     // 那么直接答案就是当前的答案加上剩余的奇数

// }

void solve()
{
    int n; cin >> n;
    int co = 0, cj = 0;
    int maxj = 0, maxo = 0, maxv = 0;
    int pos = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
        if(w[i] % 2 == 0) co++;
        else cj++;
        maxo = max(maxo, w[i]);
        
        if(w[i] > maxj && w[i] % 2 == 1)
        {
            pos = i;
            maxj = max(w[i], maxj);
        }
        if(w[i] % 2 == 0)
            q.push(w[i]);
    }
    bool f = false;
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     if(w[i] % 2 == 0 && w[i] < maxj)
    //     {
    //         maxj += w[i];
    //         if(maxj > maxo)
    //         {
    //             // 说明到这就够了
    //             f = true;
    //         }
    //         co--;
    //     }
    // }
    if(!co || !cj)
    {
        cout << "0\n";
        return;
    }
    while(q.size())
    {
        int x = q.top();
        q.pop();
        if(x > maxj)
        {
            break;
        }
        maxj += x;
        if(maxj > maxo)
        {
            // 说明到这就够了
            f = true;
            break;// 说明就是co
        }
    }
    // 如果正面不够

    // 如果够了, 那就不用+1
    if(f)
    {
        cout << co << "\n";
    }
    else 
    {
        cout << co + 1 << "\n";
    }

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