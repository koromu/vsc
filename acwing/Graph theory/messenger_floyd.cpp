#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 110;
int n, m;
int g[N][N];
int ans;

int floyd()
{
    memset(g, 0x3f, sizeof g);
    for(int i = 1 ; i <= n ; i ++)
        g[i][i] = 0;

    for(int k = 1 ; k <= n ; k ++)
        for(int i = 1; i <= n ; i ++)
            for(int j = 1 ; j <= n ; j ++)
            {
                if(g[i][j] > g[i][k] + g[k][j])
                {
                    g[i][j] = g[i][k] + g[k][j];
                }//要看的就是, 能不能从一个点到所有的店
            }
    for(int i = 1 ; i <= n ; i ++) cout << g[1][i] << " ";
    for(int i = 1; i <= n ; i ++)
    {
        if(g[1][i] == 0x3f3f3f3f){
            ans = -1;
            break;
        }
        ans = max(g[1][i], ans);
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    cout << floyd() << endl;

    
    return 0;
}
