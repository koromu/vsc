#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    string a, b; cin >> a >> b;
    string ans = "";
    
    priority_queue<char, vector<char>, greater<char>> qa, qb;


    a = ' ' + a;
    b = ' ' + b;
    for(int i = 1 ; i <= n ; i ++)
    {
        qa.push(a[i]);
    }
    for(int i = 1 ; i <= m ; i ++)
    {
        qb.push(b[i]);
    }
    int ka = 0 , kb = 0;
    while(qa.size() && qb.size())
    {
        int aa = qa.top(), bb = qb.top();
        qa.pop();
        qb.pop();
        // cout << aa << " " << bb << "\n";
        if((ka < k && aa < bb) || kb >= k)
        {
            qb.push(bb);
            ans += aa;
            kb = 0;
            ka ++;
        }
        else/*(kb <= k && aa > bb)*/
        {
            qa.push(aa);
            ans += bb;
            ka = 0;
            kb ++;
        }
    }

    std::cout << ans << "\n";

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