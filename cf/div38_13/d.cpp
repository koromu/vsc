#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;
int pre[N];
bool st[N];

void solve()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        st[i] = false;
        cin >> w[i];
        pre[i] = pre[i - 1] + w[i];
    }
    string s; cin >> s;
    s = ' ' + s;
    int ans = 0;
    int p1 = n;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(s[i] == 'L')
        {
            bool f = false;
            for(int j = p1 ; j > i ; j --)
            {
                if(s[j] == 'R')
                {
                    ans += (pre[j] - pre[i - 1]);
                    st[i] = st[j] = true;
                    p1 = j - 1;
                    f = true;
                    break;
                }
            }
            if(!f) break;
        }
    }
    cout << ans << "\n";
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