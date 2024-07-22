#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;

const int N = 200010;
int w[N];
vector<int> v1;

int lowbit(int x) {return(x & (-x));};

void solve()
{
    int n, k; cin >> n >> k;
    // while(n && v1.size() != k - 1)
    // {
    //     // 如果和自己的lowbit不同的话, 那么就取一个lowbit, 首先要确定我们要几个数
    //     if(n == lowbit(n))
    //     {
    //         v1.push_back(1);
    //         n --;
    //     }
    //     else 
    //     {
    //         v1.push_back(lowbit(n));
    //         n -= lowbit(n);
    //     }
    // }
    // if(n % 2 == 0 || n == 1)// 如果最后这个是2的倍数
    // {
    //     v1.push_back(n);
    //     sort(v1.begin(), v1.end());
    //     for(auto i : v1) cout << i << " ";
    //     cout << endl;
    // }
    // else puts("NO");
    priority_queue<int> q;
    while(n)
    {
        q.push(lowbit(n));
        n -= lowbit(n);
    }

    while(q.size() < k)
    {
        auto i = q.top();
        if(i == 1)
        {
            puts("NO");
            return;
        }
        q.pop();
        q.push(i / 2);
        q.push(i / 2);
    }
    if(q.size() == k)
    {
        puts("YES");
        while(!q.empty()) 
        {
            v1.push_back(q.top());
            q.pop();
        }
        sort(v1.begin(), v1.end());
        for(auto i : v1) cout << i << " ";
    }
    else puts("NO");

    return ;
}


signed main()
{
    int _ = 1; // cin >> _;
    while(_--) solve();
    return 0;
}