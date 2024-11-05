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
    vector<int> v1;
    while(n)
    {
        v1.push_back(n % 10);
        n /= 10;
    }
    reverse(v1.begin(), v1.end());

    if(v1.size() <= 2)
    {
        cout << "NO\n";
        return;
    }
    if(v1[0] == 1 && v1[1] == 0 && (v1[2] >= 2 || (v1.size() >= 4 && v1[2] != 0)))
    {
        cout << "YES\n";
    }
    else 
    {
        cout << "NO\n";
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