#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int n;
bool flag = false;
// void dfs(int u, auto &ans)
// {
//     if(u == n)
//     {
//         //说明已经把这个数组都准备好了
//         for(auto i : ans) cout << i << " ";
//         flag = true;
//         return;
//     }

//     for(int i = 1 ; i <= 5&& !flag ; i ++)
//     {
//         if(ans[u - 1] * i + x[i - 1]  <= x[i]) continue;
//         else {
//             ans.push_back(ans[u - 1] * i + x[i - 1]);
//             dfs(u + 1, ans);//这一位已经弄好了
//             ans.pop_back();
//         }
//     }
// }

void solve()
{
    vector<int> ans;
    cin >> n;
    ll x[510];
    // memset(x, 0, sizeof x);
    for(int i = 0 ; i < n - 1 ; i++) cin >> x[i];
    ans.push_back(x[0] + 1);
    ll tmp = x[0] + 1;
    for(int i = 0 ; i < n - 1 ; i ++) {
        if(x[i] >= tmp)//如果5 大于 3
        {
            int hh  = 2;
            while(x[i] >= tmp)
            {
                ans[ans.size() - 1] = ans[i - 1] * (hh++) + x[i-1];
                tmp = ans[ans.size() - 1];
            }
            tmp += x[i];
        }
        else tmp += x[i];
        ans.push_back(tmp);
    }
    // for(int i = 0 ; i + 1 < ans.size() ; i ++)
    // {
    //     cout << ans[i+1] % ans[i] << " ";
    // }
    // cout << endl;
    for(auto i : ans) cout << i << " ";
    cout << endl;
    // dfs(1, ans);//从下标1开始
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

