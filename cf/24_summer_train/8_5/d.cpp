#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

int w[N];

char ans[N];
void solve()
{
    string a; cin >> a;
    int n; cin >> n;
    a = ' ' + a;
    priority_queue<pair<char, int>> q;
    for(int i = 1 ; i <= max(n, 27) ; i ++) ans[i] = 0;
    for(int i = 1 ; i <= a.size() - 1 ; i ++)
    {
        // cout << (a[i] - 'a' + 1) << "\n";
        ans[(a[i] - 'a' + 1)] ++;// 字符出现了一次
    }
    for(int i = 1 ; i <= 26 ; i ++)
    {
        if(ans[i])
        {
            q.push({(char)(i + 'a' - 1), ans[i]});
            // cout << (char)(i + 'a' - 1) << " ";
        }
    }
    // cout << "\n";
    
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
    }   
    char f;
    for(int t = 1 ; t <= n ; t ++)
    {
        vector<int> v1; 
        int c = 0;
        char op;
        for(int i = 1 ; i <= n ; i ++) if(w[i] == 0) c++;// 然后选定这次要用的字母
        while(q.size())
        {
            if(q.top().second >= c)
            {
                op = q.top().first;
                q.pop();
                break;
            }
            else q.pop();
        }
        // 退出来了就是找到答案了
        for(int i = 1 ; i <= n ; i ++)
        {
            if(w[i] == 0)
            {
                w[i] = -1;
                ans[i] = op;
                v1.push_back(i);
            }
        }

        // for(int i = 1 ; i <= n ; i ++)// 最后一个是0说明字符串中最大的, 
        // {
        //     if(w[i] == 0)
        //     {
        //         w[i] = -1;
        //         // 取出最大的填上
        //         auto tmp = q.top();
        //         ans[i] = tmp.first;// 这个字符装上去了
        //         // cout << tmp.first << "\n";
        //         f = tmp.first;
        //         tmp.second --;
        //         q.pop();
        //         if(tmp.second) q.push(tmp);// 否则不用进去了
        //         v1.push_back(i);
        //         cout << "i : "  << i << "\n";
        //     }
        // }

        // 处理一遍之后还要处理其他的东西
        
        // if(q.top().first == f)// 只用一次
        // {
        //     q.pop();
        // }
        
        for(auto t : v1)
        {
            for(int i = 1 ; i <= n ; i ++)
            {
                w[i] -= abs((i - t));// 此时会出现负数 
            }
        }
    }
    for(int i = 1 ; i <= n ; i ++) cout << ans[i] << "" ;
    cout << "\n";
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