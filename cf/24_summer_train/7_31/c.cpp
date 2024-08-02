#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 55;
int n;

int w[N];
map<int, int> mp;

bool check(int x)
{
    map<int, int> m1(mp);
    // for(auto i : m1) cout << i.first << " " << i.second << "\n";
    for(int i = 1 ; i <= n ; i ++)
    {
        m1[w[i]]--;
        if(m1[x - w[i]] && x - w[i] > 0)
        {
            // 如果存在的话, 那么直接可以继续了
            m1[x - w[i]]--;
        }
        else return false;
    }
    return true;
}       

void solve()
{
    cin >> n;
    
    for(int i = 1 ; i <= n ; i ++){
        cin >> w[i];
        mp[w[i]] += 2;
    }
    sort(w + 1 , w + n + 1);
    int l = 1, r = n;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid))
        {
            l = mid;
        }
        else r = mid - 1;
    }
    cout << "l : " << l << "\n";
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();

return 0;
}