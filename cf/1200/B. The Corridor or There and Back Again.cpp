#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
// typedef long long ll;


void solve()
{
    // map<int, int> ha;
    int n;
    cin >> n;
    int x, y;
    int ans = 1e9;
    // int fs = 1e9, fd = 1e9;
    for(int i = 1;  i <= n ; i ++)
    {
        cin >> x >> y;//每个陷阱的触发时间
        if(y % 2 == 0) 
            ans = min(x + (y - 1) / 2, ans);
        else
            ans = min(x + y / 2, ans);
    }
    cout << ans << endl;
    
}


int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}