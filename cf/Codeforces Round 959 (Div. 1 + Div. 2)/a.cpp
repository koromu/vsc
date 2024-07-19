#include <iostream>
using namespace std;
// #define endl "\n"
#define int long long
#define pii pair<int, int>
// #define l first
// #define r second
const int N = 20 + 5, M = 0;

int w[N][N];

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> w[i][j];
            // std::cout << w[i][j] << " ";
        }
    }
    // std::cout << endl;
    if(n == 1 && m == 1) puts("-1");
    else if(n == 1 && m > 1)
    {
        for(int i = 2 ; i <= m ; i ++) 
        {
            std::cout << w[1][i] << " ";
        }
        std::cout << w[1][1] << endl;
        return;
    }
    else if(m == 1 && n > 1)
    {
        for(int i = 2 ; i <= n ; i ++)
        {
            std::cout << w[i][1] << " ";
        }
        std::cout << w[1][1] << endl;
        return;
    }
    else if(n > 1 && m > 1)
    {
        for(int i = 1; i <= n ; i ++)
        {
            for(int j = 2 ;j <= m ; j ++)
            {
                std::cout << w[i][j] << " ";
            }
            std::cout << w[i][1] << endl;
        }
    }
    // std::cout << endl;
}
signed main()
{
    int t = 1;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
