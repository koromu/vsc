#include <iostream>

using namespace std;

const int N = 110;

string map[N];
int xa, ya, xb, yb;
int n;
int dx[4]= {0, 1, 0, -1};
int dy[4]= {1, 0, -1, 0};

bool dfs(int x, int y)
{
    if(x == xb && y == yb)
        // cout << x << " " << y << endl;
        return true;

    for(int i = 0 ; i < 4 ; i ++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
        if(map[xx][yy] == '#') continue;
        
        map[xx][yy] = '#';
        if(dfs(xx, yy)) return true;
        // 如果只是连通性, 存在性, 也就是人体内部搜索, 为了某一个点只搜索一次, dfs不需要恢复现场
        // 还有另外一种是需要恢复现场的, 看的是一个状态能不能到另一个状态, 不是在人体内部了, 这类类问题需要恢复现场

        // 也就是其实如果只是用了这个一个st数组判断的话, 我们并没有改变这个图的状态, 所以不需要恢复现场
    }
    return false;
}

void solve()
{
    cin >> n;
    // cout << n << endl;
    char a[10];
    // cin.ignore();
    for(int i = 0 ; i < n ; i ++)
    {
        getline(cin, map[i]);
        cout << map[i] << endl;
    }

    cin >> xa >> ya >> xb >> yb;
    // cout << xb << " " << yb << endl;
    if(map[xa][ya] == '#' || map[xb][yb] == '#')
    {
        puts("NO");
        return ;
    }
    map[xa][ya] = '#';
    if(dfs(xa, ya)) puts("YES");
    else puts("NO");
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