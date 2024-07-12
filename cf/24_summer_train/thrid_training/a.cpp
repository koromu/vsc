#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 1010;

void solve()
{       
    int x[3];
    unordered_map<int,int> ha;
    for(int i = 0 ; i < 3 ; i ++) {
        cin >> x[i];
    }
    sort(x, x + 3);
    for(int i = 0 ; i < 3 ; i ++)
    {
        ha[x[i]] = x[i];
        // cout << ha[x[i]] << endl;
    }


    if(x[2] == x[1])
    {
        puts("YES");
        cout << ha[x[1]] << ' ' << ha[x[0]] << ' ' << 1 << endl;
    }
    else puts("NO");
    
}

signed main()
{
    int _ ; cin >> _;
    while(_--) solve();
    return 0;
}
