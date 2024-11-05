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
    int k; cin >> n >> k;
    map<int, int> ha;
    bool f = false;
    w[0] = -P;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
        // cout << w[i] << " " << w[i - 1] << "\n";
        if(w[i] < w[i - 1])
        {
            f = true;// 说明这个式子不递增
        }
        ha[w[i]]++;
    }

    if(f){
        if(ha.size() == 1)
        {
            cout << "YES\n";
            return;
        }
        else 
        {
            if(k >= 2)
            {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
            return;
        }
    }
    else {
        cout << "YES\n";
        // cout << "?\n";
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