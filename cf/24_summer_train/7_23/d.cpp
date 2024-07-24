#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>

#define int long long

using namespace std;
const int N = 2e5 + 10;
int w[N];

void solve()
{
    int n; cin >> n;
    map<int, int> ha;
    ha.clear();
    priority_queue<int> q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> w[i];
        ha[w[i]] ++;// 这个数出现的次数加1, 然后每次取出出现次数第一和第二多的数删掉
    }
    for(auto i : ha)
    {
        q.push(i.second);// 出现次数
        // cout << i.first << " " << i.second << endl;
    }
    // cout << endl;
    
    while((int)q.size() >= 2)
    {
        int x1 = q.top();
        q.pop();
        int x2 = q.top();
        q.pop();
        x1--, x2--;
        if(x1 > 0) q.push(x1);
        if(x2 > 0) q.push(x2);
    }
    int ans = 0;
    while((int)q.size())
    {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}