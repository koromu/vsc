#include <iostream>
#include <algorithm>
#include <queue>

#define int long long
using namespace std;
const int N = 1e4 + 10;
typedef pair<int, int> pii;

int n, m;
bool st[N << 1 + 10];
void bfs()
{
    queue<pii> q;
    q.push({n, 0}); // 第一个是当前参数, 第二个是步数, 因为是bfs第一个走到这个数字的是最少步数
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        if(t.first == m)
        {
            cout << t.second << endl;
            return; 
        }
        // 取出第头元素
        // 减一下枝
        // 如果乘二大于m的, 减1变成小于等于0的, 直接continue, 下一步走过了的
        // 剩下的就是需要加入的
        // if(t.first * 2 > m || t.first - 1 <= 0) continue;

        if(!st[t.first * 2] && t.first * 2 <= 2 * m) 
        {
            q.push({t.first * 2, t.second + 1});
            st[t.first * 2] = true;
        }
        if(!st[t.first - 1] && t.first - 1 > 0) 
        {
            q.push({t.first - 1, t.second + 1});
            st[t.first - 1] = true;
        }
    } 
}

signed main()
{
    cin >> n >> m;
    bfs();
    return 0;
}

