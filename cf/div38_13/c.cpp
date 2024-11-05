#include <bits/stdc++.h>
//using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;
int w[N];
int n;
int a[N];
string s[N];
int st[27];
void solve()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> a[i];
        a[i] += P;
    }
    int k; cin >> k;
    for(int i = 1 ; i <= k ; i ++) cin >> s[i];

    for(int i = 1 ; i <= k ; i ++)
    {
        for(int j = 0 ; j <= 26 ; j ++) st[j] = 0;
        map<char, int> mp;
        bool f = false;
        if(s[i].size() != n)
        {
            cout << "NO\n";
            continue;
        }
        map<int, int> ss;
        for(int j = 0 ; j <= s[i].size() - 1 ; j ++)
        {
            // cout << "a:" << a[j + 1] << "\n";
            if(st[(int)(s[i][j] - 'a')] == 0 && ss[a[j + 1]] == 0)// 字母没出现，数没出现
            {
                // cout << "个数 : " << ss.count(a[j + 1]) << "\n";
                ss[a[j + 1]]++;
                mp[s[i][j]] = a[j + 1];
                // cout << s[i][j] << " " << a[j + 1] << "\n";
                st[(int)(s[i][j] - 'a')] ++;
            }
            else if(st[(int)(s[i][j] - 'a')] == 0 && ss.count(a[j + 1]) != 0)// 虽然这个字母没出现过，但是数出现了
            {
                // 否则已经出现过了
                // cout << s[i][j] << "\n";
                // cout << mp[s[i][j]] << " " << a[j + 1] << "\n";
                // if(mp[s[i][j]] != a[j + 1])
                // {
                    cout << "NO\n";
                    f = true;
                    break;
                // }
            }
            else if(st[(int)(s[i][j] - 'a')] != 0 && ss[a[j + 1]] == 0)// 字母出现过，数没出现
            {
                cout << "NO\n";
                f = true;
                break;
            }
            else if(st[(int)(s[i][j] - 'a')] != 0 && ss[a[j + 1]] != 0)
            {
                if(mp[s[i][j]] != a[j + 1])
                {
                    cout << "NO\n";
                    f = true;
                    break;
                }
            }// 字母出现过，数也出现过

        }
        
        if(!f)
            cout << "YES\n";
    }

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