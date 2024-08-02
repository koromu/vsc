#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
vector<int> v1;

int prime[N * 2];
bool st[N + 10];
int idx;

// void init()
// {
//     memset(st, true, sizeof(st));
//     st[1] = false;
//     for (int i = 2; i <= N; i++)
//     {
//         if (st[i])
//             prime[++idx] = i;
//         for (int j = 1; j <= idx && i * prime[j] < N; j++)
//         {
//             st[i * prime[j]] = false;
//             if (i % prime[j] == 0)
//                 break;
//         }
//     }
// }

void solve()
{
    v1.clear();
    int n;
    cin >> n;
    // cout << n << endl;
    // 后一个可以被前一个整除
    // 全部大于1
    // k要最长
    // 相乘得n
    // if(n % 2 == 1)
    // {
    //     v1.push_back(n);
    // }
    // else
    // for(int i = 1 ; i <= idx - 1 ; i ++) std::cout << prime[i] << " ";
    // std::cout << endl;
    // std::cout << idx << endl;
    bool flag = false;
    int ans = 0;
    int pp = 2;
    for(int i = 1 ; n / prime[i] >= prime[i] && i <= idx ; i ++)
    {
        int tmp = n;
        int c = 0;
        // cout << prime[i] << " ";
        while(tmp % prime[i] == 0)
        {
            flag = true;
            c++;
            if((tmp / prime[i]) % prime[i] != 0) break;
            tmp /= prime[i];
        }
        if(c > ans)
        {
            ans = c;
            pp = prime[i];
        }
        // cout << c << endl;
        // if(flag) break;
    }
    // cout << ans << " " << pp << endl;
    if(ans == 0 || ans == 1)
    {
        cout << 1 << endl;
        cout << n << endl;
        return;
    }
    cout << ans << endl;
    for(int i = 1 ; i <= ans - 1 ; i ++)
    {
        cout << pp << " ";
        n /= pp;
    }
    cout << n << endl;
    
    // cout << endl;
    // std::cout << v1.size() << endl;
    // for(int i = v1.size() - 1; i >= 0 ; i --) std::cout << v1[i] << " ";
    // for (auto i : v1)
    //     std::cout << i << " ";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // init();
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
}