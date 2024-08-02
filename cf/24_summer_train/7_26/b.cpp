#include <bits/stdc++.h>
// #define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 2e5 + 10;


void solve()
{
    int n; cin >> n;
    int a[N];
    // priority_queue<pii , vector<pii>, greater<pii>> q;
    map<int, int> q;
    for(int i = 1 ; i <= n ; i ++) 
    {
        int tmp; cin >> tmp;
        q[tmp] ++;
        a[tmp] = i; 
    }
    int c = 0;int pos = 0;
    for(auto i : q)
    {
        // cout << i.second << " ";
        if(i.second == 1) {
        cout << a[i.first] << endl;
        return;
        }
    }
    // cout << endl;
        cout << "-1" << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
     cin >> _;
    while(_--)
    {
        solve();
    }
}