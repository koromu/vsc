#include <iostream>

using namespace std;
const int N = 100010;
int a, b, c, d, q;
int P = 998244353;
int f[N][N], s[N];

void init(int a, int b, int c, int d, int q)
{
    for(int i = 0 ; i <= N; i ++) f[i][0] = f[0][i] = d;
    for(int n = 1 ; n <= N; n ++)
    {
        for(int m = 1 ; m + n <= N ; m ++)
        {
            f[m][n] = a * f[m-1][n] + b * f[m][n-1] + c * f[m-1][n-1];
        }
    }
}


int main()
{
    cin >> a >> b >> c >> d >> q;
    init(a, b, c, d, q);
    int k;
    int ans = 0;
    while(cin >> k)
    {
        for(int i = 0 ; i <= k ; i ++)
        {
            for(int j = 0 ; j + i <= k ; j ++)
            {
                ans += f[i][j];
            }
        }
        cout << (ans % P) << endl;
    }
    
    
    return 0;
}