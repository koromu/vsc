#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 510;
bool cmp(int a, int b )
{
    return a > b;
}
void solve()
{
    char map[N][N];
    int n, m; cin >> n >> m;
    bool flag = false;
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < m ; j ++)
        {
            cin >> map[i][j];
        }
    }

    if(n == 1)
    {
        //如果有一个是1
        if(map[0][0] != map[0][m - 1])
            puts("NO");
        else puts("YES");
        return;
    }
    if(m == 1)
    {
        if(map[0][0] != map[n - 1][0])
            puts("NO");
        else puts("YES");
        return;
    }

    //先遍历四条边
    char up_right = map[0][m - 1];
    char up_left = map[0][0];
    char down_right = map[n - 1][m - 1];
    char down_left = map[n - 1][0];

    for(int i = 0 ; i < m ; i ++)
    {
        if(up_left != map[0][i])
        {
            flag = true;
            break;
        }
    }
    if(!flag)//如果有一条边同色
    {
        //那么判断对边是否有完全不同的颜色
        for(int i = 0 ; i < m ; i ++)
        {
            if(up_left == map[n - 1][i])
            {
                flag = true;
                break;
            }//如果一个同色, 说明对边不是完全不同颜色的边
        }//否则对面就是一个不同, no
        if(!flag)
        {
            puts("NO");
            return ;
        }
        else {
            puts("YES");
            return ;
        }
    }//如果上边不同色
    
    flag = false;
    for(int i = 0 ; i < n ; i ++)
    {
        if(up_left != map[i][0])
        {
            flag = true;
            break;
        }
    }
    if(!flag)//如果左边同色
    {
        //那么判断对边是否有完全不同的颜色
        for(int i = 0 ; i < n ; i ++)
        {
            if(up_left == map[i][m - 1])
            {
                flag = true;
                break;
            }//如果一个同色, 说明对边不是完全不同颜色的边
        }//否则对面就是一个不同, no
        if(!flag)
        {
            puts("NO");
            return ;
        }
        else {
            puts("YES");
            return ;
        }
    }//如果上边不同色
    //如果上和左都没有同色的
    puts("YES");
}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
}