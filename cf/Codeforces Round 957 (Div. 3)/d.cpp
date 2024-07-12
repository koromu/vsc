#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;
int n, m, k;
string a; 

void solve()
{   
    cin >> n >> m >> k;
    cin >> a;
    // 首先在岸上, 直接跳跃到最远的木头上
    // 遍历一遍字符串
    // 如果现在是L C W
    // 如果是W, 就往前遍历k个格子, 是否有陆地
    for(int i = 0 ; i < a.size() ;)
    {
        if(i == 0 || a[i] == 'L')
        {
            if(i + m >= a.size())
            {
                puts("YES");
                return;
            }
            bool f1 = false;
            for(int j = m - 1 ; j >= 0 ; j --)
            {
                if(a[i + j] == 'L')
                {
                    i += j;// 跳到这里来
                    f1 = true;
                    break;
                }
            }
            if(!f1)
            {
                // 如果没找到
                for(int j = m - 1 ; j >= 0 ; j --)
                {
                    if(a[i + j] == 'W')
                    {
                        i += j;// 跳到这里来
                        f1 = true;
                        break;
                    }
                }
            }
            if(!f1) 
            {
                puts("NO");
                return;
            }
        }
        int posc = -1, posl = -1;
        if(a[i] == 'W')
        {
            if(i + k >= a.size())
            {
                puts("YES");
                return;
            }
            for(int j = 0 ; j < k ; j ++)
            {
                if(a[i + j] == 'C')
                {
                    posc = i + j;
                    break;
                }
            }
            // 或者出来了
            for(int j = 0 ; j < k ; j ++)
            {
                if(a[i + j] == 'L')
                {
                    posl = i + j;
                    break;
                }
            }
            if(posc < posl || posl == -1)
            {
                puts("NO");
                return;
            }
            else
            {
                i += posl;
            }
        }
    }
    puts("YES");
    return;
}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
