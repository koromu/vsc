#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;

void solve()
{
 // 要是一个字符串,使得子串种从左到右从右到左的读起来相同的字符串最少
    int n; cin >> n;
    string s = "";
    string ss[6] = { " ", "a", "e", "i", "o", "u"};
    for(int i = 0; i <= n - 1 ; i ++)
    {
        s += ss[i % 5 + 1];// 直接摸得到的时候0 ~ 5, + 1 变成1 ~ 6
    }
    cout << s << "\n";
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}