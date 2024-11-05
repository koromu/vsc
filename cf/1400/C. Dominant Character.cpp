#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int n; 

void solve()
{
    cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    int ans = 1e9 + 7;
    // aa aba aca abca acba accabba abbacca
    // 确实牛逼啊, 观察样例得到这个最短的话就是从aa 到 abbacca总共其中子串表示, 四个a的最短串可以被前面的7钟子串表示
    // 所以枚举左端点, 然后对于每一个左端点往后枚举7个位置
    for(int i = 1 ; i <= n ; i ++)
    {
        if(s[i] == 'a')
        {
            int ca = 1, cb = 0, cc = 0;
            // 那么再看后面的7个位置
            for(int j = i + 1 ; j <= min(n, i + 6); j ++)
            {
                if(s[j] == 'a')ca++;
                else if(s[j] == 'b') cb++;
                else cc++;
                if(ca > cb && ca > cc)
                    ans = min(ans, j - i + 1);
            }
        }
    }
    if(ans == P) 
    {
        cout << "-1\n";
        return;
    }
    cout << ans << "\n";
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();

return 0;
}