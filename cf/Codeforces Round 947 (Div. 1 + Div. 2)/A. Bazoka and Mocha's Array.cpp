#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 55;

int w[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> w[i];
    for(int i  = 1; i <= n ; i ++)
    {
        bool f1 = true, f2 = true;
        for(int j = 1 ; j < i ; j ++)
        {
            if(w[j] > w[j + 1]){
                f1 = false;
                break;
            }
        }
        if(f1)
        {
            // 如果前面那个是升序的话, 再判断后面这个
            for(int j = i + 1 ; j < n ; j ++)
            {
                if(w[j] > w[j + 1]){
                    f2 = false;
                    break;
                }
            }
        
            if(f2)
            {
                // 如果f2也是合法的, 那么再判断这两端能不能组合成
                // 要么是分界处的左边小于右边
                // 要么是左边区间开头大于右边区间的结尾
                if(w[1] >= w[n])
                {
                    puts("YES");
                    return ;
                }
                if(i != n)
                {
                    if(w[i] <= w[i + 1])
                    {
                        puts("YES");
                        return ;
                    }
                }
            }
        }
    }
    puts("NO");
}

signed main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}