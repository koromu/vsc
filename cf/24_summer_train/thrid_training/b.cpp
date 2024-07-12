#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 1010;

int a[N];
bool st[N];

void solve()
{       
    int n; cin >> n;
    for(int i = 0 ; i < 2 * n ; i ++)
    {
        cin >> a[i];
    }
    memset(st, 0, sizeof st);
    for(int i = 0; i < 2 * n ; i ++)
    {
        if(!st[a[i]])
        {
            cout << a[i] << " ";
            st[a[i]] = true;
        }
    }
    cout << endl;
}

signed main()
{
    int _ ; cin >> _;
    while(_--) solve();
    return 0;
}
