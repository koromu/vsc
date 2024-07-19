#include <iostream>
#include <string>
#include <algorithm>
#include <queue>


#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 5010;
int C[N][N];
int n, m, p; 
int qmi(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void init()
{
    C[1][0] = C[1][1] = 1;
    for(int i = 2; i <= n ; i ++)
    {
        for(int j = 0 ; j <= i ; j ++)
        {
            if(j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            // cout << C[i][j] << " ";
        }
    }
}

signed main()
{
    cin >> n >> m >> p;
    init();
    int ans = 0;
    for(int k = 1; k <= n ; k ++)
    {
        // cout << " C[" << n << "," << k << "] : " << C[n][k] << " * " << qmi((qmi(2, k, p) - 1), m - 1, p) << " * " << qmi(qmi(2, m - 1, p) % p, n - k, p) << " = " << C[n][k] * qmi((qmi(2, k, p) - 1), m - 1, p) * qmi(qmi(2, m - 1, p) % p, n - k, p) << endl; 
        ans = (ans + C[n][k] * qmi((qmi(2, k, p) - 1), m - 1, p) * qmi(qmi(2, m - 1, p) % p, n - k, p) ) % p;
    }
    cout << ans << endl;

    return 0;
}
