#include <bits/stdc++.h>
// using i64 = long long;
#define int long long
using namespace std;

const int P = 1e9 + 7;
const int N = 200010;
int w[N];
int n;

void solve()
{
    int l = 1, r = 999;
    int now = 0;
    while (l < r)
    {
        int lmid = l + r / 3 + l;
        int rmid = (l + r) / 3 * 2 + l >> 1;
        cout << "? " << lmid << " " << rmid << endl;
        cin >> now;
        if (now == lmid * rmid)
            l = rmid + 1;
        else if (now == lmid * (rmid + 1))
            l = lmid + 1, r = rmid;
        else
            r = lmid;
    }
    cout << "! " << l << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}