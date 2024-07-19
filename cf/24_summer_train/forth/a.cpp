#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 500010;

void solve()
{
    unordered_map<int, int> ha;
    string a ; cin >> a;
    for(int i = 0 ; i < a.size() ; i ++)
    {
        ha[a[i] - 'a'] = i;// 每个字母的位置
    }
    string b; cin >> b;
    int ans = 0;
    for(int i = 1 ; i < b.size() ; i++)
    {
        ans += abs(ha[b[i] - 'a'] - ha[b[i-1] - 'a']);
    }
    cout << ans << endl;
}

signed main()
{
    int _; cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
