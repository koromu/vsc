#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 110;
int n; 
unordered_map<int, int> ha;
int q[N], w[N];// 手写一个队列
int hh = 0, tt = -1, maxv = 0;

void dfs(int u, int now)
{
    // cout << "u : " << u <<  " now : " <<  now << endl;
    // cout << "ha[2 * now] != 0 : " << (ha[2 * now] != 0) << endl;
    // cout << "now * 2 <= maxv : " << (now * 2 <= maxv) << endl;
    // cout <<  "now % 3 == 0 : " << (now % 3 == 0) << endl;
    // cout << "ha[now / 3] != 0 : " << (ha[now / 3] != 0) << endl;
    if(u == n) 
    {
        for(int i = hh ; i <= tt ; i ++)
            cout << q[i] << " ";
        exit(0);
    }
    // cout << endl;
    // 两种可能
    if(ha[2 * now] != 0 && now * 2 <= maxv)// 如果下一个*2存在的话
    {
        q[++tt] = 2 * now;
        ha[2 * now]--;
        dfs(u + 1, 2 * now);
        ha[2 * now]++;// 恢复现场
        tt--;
    }
    if(now % 3 == 0 && ha[now / 3] != 0)// 如果下一个*2存在的话
    {
        q[++tt] = now / 3;
        ha[now / 3]--;
        dfs(u + 1, now / 3);
        ha[now / 3]++;// 恢复现场
        tt--;
    }
}

signed main()
{
    cin >> n;
    // 统计每个数出现的个数
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> w[i];
        maxv = max(maxv, w[i]);
        ha[w[i]]++;// 知道了这个以后, 就可以进行组合了
    }
    // for(auto i : ha) cout << i.first << " " << i.second << endl;
    for(int i = 0 ; i < n ; i ++)// 遍历所有的起点
    {
        ha[w[i]]--;
        q[++tt] = w[i];
        dfs(1, w[i]);
        ha[w[i]]++;
        tt--;// 恢复一下
    }
    return 0;
}
