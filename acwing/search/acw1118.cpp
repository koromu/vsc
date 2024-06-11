#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 15;
int n;
int w[N];
int g[N][N];// 第i个组的第j个数是多少
int ans = 10;
bool st[N];
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

bool check(int u, int x, int gc)//1 2 0
{
    if(gc== 0) return true;
    for(int i = 1 ; i <= gc; i ++)
    {
        // cout << w[x] << " " << g[u][i] << endl;
        if(gcd(w[x], w[g[u][i]]) != 1 || gcd(w[x], w[g[u][i]]) == 0) return false;
    }
    // cout << endl;

    return true;// 如果全都等于1的话
}

void dfs(int u, int gc, int tc, int gs, int ss)
{
    // cout << u << " " << gc << " " << tc << " " << gs << " " << ss << endl;
    if(gs >= ans) return ;// 如果组数超过了答案数, 那么就不用更新了, 直接剪枝
    if(tc == n)
    {
        ans = min(ans, gs);// 全部的数都分好了组, 那么可以更新答案了
    }
    // 因为是按组枚举的, 所以要枚举每一个数, 先看看这个数能不能再这个组里面, 如果是在同一组的话, 下一次枚举的话就可以从上一次枚举的末尾开始, 

    bool flag = true;
    for(int i = ss ; i <= n ; i ++)
    {
        if(st[i]) continue;
        // cout << "i : " <<  i << " u : " << u << " gc : " << gc << endl;
        if(check( u , i , gc ))// 判断的是当前这个数和这个个组的情况
        {
            st[i] = true;
            g[u][gc + 1] = i;// 第u个组的第c个数
            dfs(u , gc + 1 , tc + 1, gs , i + 1);// 组和组数没变
            st[i] = false;
            flag = false;
        }
        //如果全都没有符合的了, 可以开下一组了
    }
    // 新加一组空的
    // for(int i = 1 ; i <= gc ; i ++) cout << g[u][i] << " " ;
    // cout << endl;
    if(flag) dfs(u + 1, 0, tc, gs + 1, 1);
}


int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> w[i];
    // 按组组来枚举
    // 先来一组空的
    dfs(1, 0, 0, 1, 1);// 当前是第i组, 这个组使用了c个数, 所有组总共使用了tc个数, 当前有的组的个数gs
    cout << ans << endl;
}

// 7
// 159 182 174 111 181 75 199

// 159 182 
// 111 181 174 199
// 75