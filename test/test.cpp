#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

vector<int> e[N];
int d[N], fa[N], sz[N], dep[N];
int n, m, cnt, ans;


int main()
{
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    

}

// 我演示怎么调试 先打断点 然后点debug1 就会跳到断点 最上面是自动窗口 下面是手动窗口 按f10逐语句调试,不会进函数,f11逐步,会进函数 最上面也有按键