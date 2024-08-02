#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 1010;

string a[N];
int w[N][N];
void solve()
{
    int n, k; cin >> n >> k;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i += k)
    {
        for(int j = 0 ; j < n ; j += k)
        {
            if(a[i][j] == '1')
            {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }
    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}