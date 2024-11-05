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
    cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    bool dif = false;
    string a = "", b = "";
    for(int i = 1 ; i <= n ; i ++)
    {
        // w[i] = s[i] - '0';
        // cout << w[i];
        if(dif)
        {
            if(s[i] == '0')
            {
                a += '0';
                b += '0';
            }
            else if(s[i] == '1')
            {
                a += '0';
                b += '1';
            }
            else
            {
                a += '0';
                b += '2';
            }
        }
        else 
        {
            if(s[i] == '0')
            {
                a += '0';
                b += '0';
            }
            else if(s[i] == '1')
            {
                a += '1';
                b += '0';
                dif = true;
            }
            else
            {
                a += '1';
                b += '1';
            }
        }
    }
    // cout << "\n";

    // 因为第一位必须是1，然后分后面的为，
    // 如果是0，那两个都是0
    // 如果是1，那么一个1一个0，此时已经分出大小了
    // 如果分出大小了，小的给1，大的给0，没分出来的话就然后标记a大
    // 如果是2，如果分成大小了，那么大的是0，小的是2
    // 如果没分出大小那么，都得1
    cout << a << "\n" << b << "\n";


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