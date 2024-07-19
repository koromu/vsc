#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;

char mp[N][N];
int cnt[4][N][N];

// 用一个编号记录当前这一个光, 然后走过的路标记成这个光的符号, 然后再
pii dfs(int c, int x, int y, int u)
{
    // 当前在x, y然后再走了u步, 如果碰到了已经走过的路, 也就是和这个当前这光标记相同的话, 那么开始回退, 每一步把当前这个点查到一个数组中path(存一下当前这个点是x, y, 光从c射过来), 然后返回值有一个参数是flag, 0是链, 1是环
    // 是环的话, 出来之后取出这些path, 把他们全部变成u
    // 搜索每一个点
}

signed main()
{
    int n, m; cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> mp[i + 1];
    }
    // 每个点有上下左右,

    return 0;
}