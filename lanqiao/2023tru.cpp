#include <iostream>

using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
int n, k;
int l[N];
int g[N][N];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = c;
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &l[i]);
        ans += g[l[i - 1]][l[i]];
    }
    

    return 0;
}